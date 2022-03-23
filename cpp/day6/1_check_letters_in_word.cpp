#include <iostream>
#include <cctype>
using namespace std;

#define MAX_LINE_LENGTH 100

int wordCounter(const char[]);

int main()
{
    char line[MAX_LINE_LENGTH]{};
    cout << "Input: ";
    cin.getline(line, 100);

    cout << "Found " << wordCounter(line)
         << " Words containing exactly 2 letters 'B'" << endl;
    return 0;
}

int wordCounter(const char line[])
{
    int letter{'B'};
    int space{' '};
    int count{0};
    int lettersFound{0};
    for (int i{0}; i < MAX_LINE_LENGTH; ++i)
    {
        line[i] == letter && lettersFound++;
        if (line[i] == space || line[i] == '\0')
        {
            lettersFound == 2 && count++;
            lettersFound = 0;
        }
    }
    return count;
}