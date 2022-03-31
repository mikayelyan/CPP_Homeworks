#include <iostream>
#include <ctime>
#include <climits>

using namespace std;

#define size 100

int *initArray(int[], int);
void findLongestAscendingRange(int[], int);
void printArray(int[], int);

int main()
{
    int numbers[size]{};
    initArray(numbers, size);
    printArray(numbers, size);
    findLongestAscendingRange(numbers, size);
}

int *initArray(int numbers[], int length)
{
    srand(time(nullptr));
    for (int i{}; i < size; ++i)
    {
        numbers[i] = rand() % 200 + (-100);
    }
    return numbers;
}

void printArray(int array[], int length)
{

    cout << "[ ";
    for (int i{}; i < size; ++i)
    {
        cout << (array[i]) << " ";
    }
    cout
        << "]" << endl;
}

void findLongestAscendingRange(int numbers[], int length)
{
    int minIndex{};
    int currentIndex{};
    int longestRange{};
    int currentRange{};
    for (int i{}; i < length - 1; ++i)
    {
        if (numbers[i] > numbers[i + 1])
        {
            if (currentRange > longestRange)
            {
                longestRange = currentRange;
                currentRange = 0;
                minIndex = currentIndex;
            }
            currentIndex = i + 1;
            currentRange = 0;
        }
        else
        {
            currentRange++;
        }
    }

    cout << endl << "Output: [ ";
    for (int i{minIndex}; i < minIndex + longestRange; ++i)
    {
        cout << (numbers[i]) << " ";
    }
    cout
        << "]" << endl;
}