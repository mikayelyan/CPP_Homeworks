#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string input{};
    cout << "Please enter a text: ";
    getline(cin, input);

    ifstream in_file;
    in_file.open("1_correct_words.txt");
    int wordsCount{};
    if (in_file)
    {
        while (!in_file.eof())
        {
            string word{};
            getline(in_file, word);
            wordsCount++;
        }
    }
    in_file.close();

    string correctWords[wordsCount];
    int index{};
    in_file.open("1_correct_words.txt");
    if (in_file)
    {
        while (!in_file.eof())
        {
            string word{};
            getline(in_file, word);
            correctWords[index] = word;
            index++;
        }
    }
    in_file.close();

    istringstream text{input};
    ostringstream outputText{};
    while (!text.eof())
    {
        string currentWord {};
        text >> currentWord;
        {
            bool isCorrect = false;
            bool isCorrected = false;
            for (int i{}; i < wordsCount; ++i)
            {
                if (currentWord == correctWords[i])
                {
                    outputText << currentWord << " ";
                    isCorrect = true;
                }
            }
            if (!isCorrect)
            {
                for (int i{}; i < wordsCount; ++i)
                {
                    if (currentWord.length() == correctWords[i].length() && currentWord.length() > 1)
                    {
                        size_t matchesCount{};
                        for (size_t k{}; k < currentWord.length(); ++k)
                        {
                            if (tolower(currentWord[k]) == tolower(correctWords[i][k]))
                                matchesCount++;
                        }
                        if (matchesCount == currentWord.length() - 1)
                        {
                            outputText << correctWords[i] << " ";
                            isCorrected = true;
                            break;
                        }
                    }
                }
            }
            if (!isCorrect && !isCorrected)
            {
                outputText << currentWord << " ";
            }
        }
    }
    
    cout << "Input: " << input << endl;

    cout << "Output: " <<outputText.str() << endl;

    return 0;
}
