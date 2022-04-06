#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string *getFiles();
bool checkInput(string);
void formatDate(string *);
string getDayFormat(string);
bool isLeapYear(int);

int main()
{
    
    string input{};
    string command{};
    while (input != "exit" && command != "exit")
    {
        cout << "Input date: ";
        getline(cin, input);
        while (!checkInput(input))
        {
            cout << "Wrong input!. Plase input date in format dd/mm/yyyy: ";
            getline(cin, input);
        }
        formatDate(&input);

        ifstream outfiles{"notes/1_files.txt", ios::app};
        if (outfiles)
        {
            bool fileExists{false};
            while (!outfiles.eof())
            {
                string fileName{};
                getline(outfiles, fileName);
                if (fileName == input)
                    fileExists = true;
            }
            outfiles.close();
            if (!fileExists)
            {
                fstream outfiles{"notes/1_files.txt", ios::app};
                if (outfiles)
                {
                    outfiles << input << endl;
                }
            }
        }
        outfiles.close();

        fstream note{"notes/" + input + ".txt", ios::app};
        if (note.is_open())
        {
            cout << "Add Note: ";
            string noteInput;
            getline(cin, noteInput);
            note << noteInput << endl;
        }
        note.close();
        cout << "Do you want to add another note (command): ";
        getline(cin, command);
        while (command != "add" && command != "exit")
        {
            try
            {
                if (command != "add" || command != "exit")
                    throw 2;
            }
            catch (int &er)
            {
                if (er == 2)
                    cout << "Wrong input! Please enter command ('add' or 'exit'): ";
                getline(cin, command);
            }
        }
    }

    string *files = getFiles();
    for (int i{1}; i < stoi(files[0]); ++i)
    {
        cout << getDayFormat(files[i]) << endl;
        ifstream in_file{};
        in_file.open("notes/" + files[i] + ".txt");
        if (in_file)
        {
            string note{};
            while (!in_file.eof())
            {
                getline(in_file, note);
                cout << setw(8) << "Note: " << note << endl;
            }
            cout << endl;
        }
        in_file.close();
    }

    return 0;
}

string *getFiles()
{
    ifstream in_file;
    in_file.open("notes/1_files.txt");
    int filesCount{};
    if (in_file)
    {
        while (!in_file.eof())
        {
            string file{};
            getline(in_file, file);
            filesCount++;
        }
    }
    else
    {
        in_file.close();
        return NULL;
    }
    in_file.close();
    string *files = new string[filesCount + 1];

    in_file.open("notes/1_files.txt");
    int index{1};
    if (in_file)
    {
        files[0] = to_string(filesCount);
        while (!in_file.eof())
        {
            string file{};
            getline(in_file, file);
            files[index] = file;
            index++;
        }
    }
    in_file.close();
    return files;
}

bool checkInput(string date)
{
    if (date.length() != 10)
        return false;
    for (int i{}; i < 10; ++i)
    {
        if ((i == 2 || i == 5) && date[i] != '/')
            return false;
        if (i != 2 && i != 5 && !isdigit(date[i]))
            return false;
    }
    return true;
}
void formatDate(string *date)
{
    (*date)[2] = '-';
    (*date)[5] = '-';
};

string getDayFormat(string date)
{
    int day = stoi({date, 0, 2});
    int month = stoi({date, 3, 2});
    int year = stoi({date, 6, 4});

    int centExtraDays{};
    switch (((year - 1) % 400) / 100)
    {
    case 1:
        centExtraDays = 5;
        break;
    case 2:
        centExtraDays = 3;
        break;
    case 3:
        centExtraDays = 1;
        break;
    default:
        break;
    }
    int lastCenturyYear = ((year - 1) % 400) % 100;
    int lastCentYearExtraDays = (lastCenturyYear + lastCenturyYear / 4) % 7;
    int lastYearExtraDays{};
    for (int i{}; i < month; ++i)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            lastYearExtraDays += 3;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            lastYearExtraDays += 2;
            break;
        case 2:
            lastYearExtraDays += isLeapYear(year) ? 1 : 0;
            break;
        default:
            break;
        }
    }
    lastYearExtraDays = (lastYearExtraDays + day) % 7;
    int dayIndex = (centExtraDays + lastCentYearExtraDays + lastYearExtraDays) % 7;
    string weekday{};
    switch (dayIndex)
    {
    case 0:
        weekday = "Sun";
        break;
    case 1:
        weekday = "Mon";
        break;
    case 2:
        weekday = "Tue";
        break;
    case 3:
        weekday = "Wed";
        break;
    case 4:
        weekday = "Thu";
        break;
    case 5:
        weekday = "Fri";
        break;
    case 6:
        weekday = "Sat";
        break;
    default:
        break;
    }
    date[2] = '/';
    date[5] = '/';
    return weekday + " " + date;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}