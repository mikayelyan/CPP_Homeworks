#include <iostream>
#include <cctype>
#include <ctime>
using namespace std;

#define MAX_WORD_LENGTH 100

int getWordLength(const char[]);
void validateInput(const char[], int);
int myAtoi(const char[], int);

int main()
{
    char inputString[MAX_WORD_LENGTH];
    cout << "Please input a number: ";
    cin.getline(inputString, MAX_WORD_LENGTH);

    int wordLength = getWordLength(inputString);
    try
    {
        validateInput(inputString, wordLength);
    }
    catch (int &er)
    {
        if (er == 0)
            cout << "Invalid input! Please enter digits only" << endl;
        return 0;
    }

    int result = myAtoi(inputString, wordLength);

    cout << "Result: " << result << endl;

    return 0;
}

int getWordLength(const char word[])
{
    int count{0};
    while (word[count] != '\0' && count < MAX_WORD_LENGTH)
    {
        count++;
    }
    return count;
}

void validateInput(const char inputString[], int size)
{
    for (int i{}; i < size; ++i)
    {
        if (!isdigit(inputString[i]))
            throw 0;
    }
}

int myAtoi(const char inputString[], int size) {
    int result {};
    for(int i {}; i < size; ++i) {
        int currentDigit = inputString[i] - 48;
        result = result*10 + currentDigit; 
    }
    return result;
}
