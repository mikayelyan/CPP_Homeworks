#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include<algorithm>

using namespace std;

struct Node
{
    string city{};
    struct Node *next;
};

struct Position
{
    int a;
    int b;
    int c;
};
Position getPosition(string city);
void addToList(string city, Node *node);
void createList(string city, Node *data[26][26][26]);
void initData(Node *data[26][26][26]);
void printList(Node *head);
void toLowerCase(char word[]);
bool checkResponse(char response[]);
bool isCity(string city, Node *data[26][26][26]);
bool checkCities(string cityA, string cityB);
bool isPreviouslyEntered(string city, Node *enteredList);
string getCityName(string userInput, Node *data[26][26][26], Node *enteredCities, bool isFirst);

int main()
{
    char response[80]{};
    int activePlayer{0};
    while (!checkResponse(response))
    {
        cout << "Would you like to start the game (Y/N): " << endl;
        cin >> response;

        if (!checkResponse(response))
        {
            cout << "Wrong input!" << endl;
        }
        else
        {
            if (strcmp(response, "y") == 0 || strcmp(response, "yes") == 0)
            {
                activePlayer = 0;
            }
            else
            {
                activePlayer = 1;
            }
        }
    }

    ifstream in_file;
    in_file.open("2_cities.txt");
    if (!in_file)
    {
        cerr << "Wasn't able to open a file";
        return 1;
    }

    Node *data[26][26][26];
    initData(data);

    while (!in_file.eof())
    {
        string line{};
        getline(in_file, line);
        createList(line, data);
    }
    in_file.close();

    Node *enteredCities = new Node();
    Node *currentPosition = new Node();
    enteredCities = currentPosition;

    
    bool isFirst = true;
    string userInput{};
    getline(cin, userInput);
    string computerInput{};
    cout << "Game started. For ending the game you can type 'exit'." << endl;
    while (userInput != "exit")
    {
        if (activePlayer == 0)
        {
            cout << "Enter City: ";
            getline(cin, userInput);
            if (isCity(userInput, data))
            {
                if (isFirst || checkCities(userInput, computerInput))
                {
                    if (!isPreviouslyEntered(userInput, enteredCities))
                    {
                        cout << "You: " << userInput << endl;
                        currentPosition->city = userInput;
                        currentPosition->next = new Node();
                        currentPosition = currentPosition->next;
                        activePlayer = 1;
                    }
                    else
                    {
                        cout << "City name already entered. Try another." << endl;
                    }
                }
                else
                {
                    cout << "Wrong input!" << endl;
                    cout << "First character should match the last character of previous city name!" << endl;
                    cout << "Try again!" << endl;
                }
            }
            else
            {
                cout << "no such a city! Try again." << endl;
            }
            isFirst = false;
        }
        if (activePlayer == 1)
        {
            computerInput = getCityName(userInput, data, enteredCities, isFirst);
            cout << "Computer: " << computerInput << endl;
            currentPosition->city = computerInput;
            currentPosition->next = new Node();
            currentPosition = currentPosition->next;
            activePlayer = 0;
        }
    }
    while (enteredCities != NULL)
    {
        cout << enteredCities->city << endl;
        enteredCities = enteredCities->next;
    }
    return 0;
}

Position getPosition(string city)
{
    int a = toupper(city[0]) - 65;
    int b = city.length() > 1 ? toupper(city[1]) - 65 : a;
    int c = city.length() > 2 ? toupper(city[2]) - 65 : b;
    Position pos{a, b, c};
    return pos;
}

void createList(string city, Node *data[26][26][26])
{
    Position pos = getPosition(city);
    if (data[pos.a][pos.b][pos.c] == NULL)
    {
        Node *newCity = new Node();
        newCity->city = city;
        data[pos.a][pos.b][pos.c] = newCity;
    }
    else
    {
        addToList(city, data[pos.a][pos.b][pos.c]);
    }
}

void addToList(string city, Node *node)
{
    Node *newCity = new Node();
    newCity->city = city;

    Node *current = new Node();
    current->next = node;
    while (current->next != NULL)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        current->next = newCity;
    }
}
void printList(struct Node *head)
{
    Node *newCity = head;

    while (newCity != NULL)
    {
        cout << newCity->city << endl;
        newCity = newCity->next;
    }
}

bool isCity(string city, Node *data[26][26][26])
{
    Position pos = getPosition(city);
    Node *current = new Node();
    current = data[pos.a][pos.b][pos.c];
    transform(city.begin(), city.end(), city.begin(), ::tolower);
    while (current != NULL)
    {
        string currentCity = current->city;
        transform(currentCity.begin(), currentCity.end(), currentCity.begin(), ::tolower);
        if (currentCity == city)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool checkCities(string cityA, string cityB)
{
    if (tolower(cityA[0]) == tolower(cityB[cityB.length() - 1]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isPreviouslyEntered(string city, Node *enteredList)
{
    Node *temporary = new Node();
    temporary = enteredList;
    while (temporary != NULL)
    {
        if (temporary->city == city)
        {
            return true;
        }
        temporary = temporary->next;
    }
    return false;
}

string getCityName(string userInput, Node *data[26][26][26], Node *enteredCities, bool isFirst)
{
    srand(time(nullptr));
    int pos = !isFirst ? (tolower(userInput[userInput.length() - 1]) - 97) : rand() % 25 + 0;
    for (int i{}; i < 26; ++i)
    {
        for (int j{}; j < 26; ++j)
        {
            Node *temporary = new Node();
            temporary = data[pos][i][j];
            while (temporary != NULL)
            {
                string newCity = temporary->city;

                if (!isPreviouslyEntered(newCity, enteredCities))
                {
                    return newCity;
                }
                else
                {
                    temporary = temporary->next;
                }
            }
        }
    }
    return "You won";
}

void initData(Node *data[26][26][26])
{
    for (int i{}; i < 26; ++i)
    {
        for (int j{}; j < 26; ++j)
        {
            for (int k{}; k < 26; ++k)
            {
                data[i][j][k] = nullptr;
            }
        }
    }
}

void toLowerCase(char word[])
{
    for (long unsigned int i{}; i < strlen(word); ++i)
    {
        word[i] = tolower(static_cast<char>(word[i]));
    }
}

bool checkResponse(char response[])
{
    toLowerCase(response);

    if (strcmp(response, "yes") == 0 || strcmp(response, "y") == 0 || strcmp(response, "n") == 0 || strcmp(response, "no") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
