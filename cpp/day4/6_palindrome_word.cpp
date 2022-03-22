#include <iostream>
#include <cctype>
using namespace std;

#define MAX_WORD_LENGTH 100

int getWordLength(const char[]);
bool checkIsPalindrome(const char[], int);

int main()
{
    char word[MAX_WORD_LENGTH]{};
    cout << "Input: ";
    cin >> word;

    int length = getWordLength(word);
    bool isPalindrome = checkIsPalindrome(word, length);
    cout << "Output: " << (isPalindrome ? "true" : "false") << endl;
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

bool checkIsPalindrome(const char word[], int length)
{
    for (int i{}; i < (length / 2); ++i)
    {
        if (tolower(word[i]) != tolower(word[length - i - 1]))
        {

            return false;
        }
    }
    return true;
}