#include <iostream>
#include <ctime>
#include <climits>
#include <cmath>

using namespace std;

int **initArray(long long totalVariations, long col, int possibleVariation);
void printWords(int **array, int row, int col, string word);
int getPossibleVariations(int length);

int main()
{
    string word{};
    cout << "Please enter a word: ";
    getline(cin, word);

    long col = word.length();
    long long row = pow(static_cast<int>(col), static_cast<int>(col));

    int possibleVariations = getPossibleVariations(col);
    int **array = initArray(row, col, possibleVariations);
    printWords(array, possibleVariations, col, word);
    for (int i{}; i < possibleVariations; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
    
    return 0;
}

int **initArray(long long totalVariations, long col, int possibleVariations)
{
    int **array;
    array = new int *[possibleVariations];

    for (int i{}; i < possibleVariations; ++i)
    {
        array[i] = new int[col];
    }
    int posVarIndex{};
    int currentValue[col]{0};
    for (int i{}; i < totalVariations; ++i)
    {
        int number = i;
        int index{};
        do
        {
            if (number % col != 0)
            {
                currentValue[col - index - 1] = (number % col);
            }
            else
            {
                currentValue[col - index - 1] = 0;
            }
            number /= col;
            index++;
        } while (number != 0);
        int isPossibleVariation = true;
        for (int j{}; j < col - 1; ++j)
        {
            for (int k{j + 1}; k < col; ++k)
            {
                if (currentValue[j] == currentValue[k])
                {
                    isPossibleVariation = false;
                }
            }
        }
        if (isPossibleVariation)
        {
            for (int i{}; i < col; i++)
            {
                array[posVarIndex][i] = currentValue[i];
            }
            posVarIndex++;
        }
    }
    return array;
}

void printWords(int **array, int row, int col, string word)
{
    for (int j{}; j < row; ++j)
    {

        for (int i{}; i < col; ++i)
        {
            cout << word[array[j][i]];
        }
        cout << endl;
    }
}

int getPossibleVariations(int length)
{
    int result{1};
    while (length != 0)
    {
        result *= length;
        length--;
    }
    return result;
}
