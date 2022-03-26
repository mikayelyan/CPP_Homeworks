#include <iostream>
#include <ctime>
using namespace std;

int *initArray(int numbers[], int size);
void printArray(int array[], int size);
void printReversedArray(int array[], int size);

int main()
{
    int size{10};
    int numbers[size]{};
    initArray(numbers, size);
    cout << "Original array: " << endl;
    printArray(numbers, size);
    cout << "Reversed array: " << endl;
    printReversedArray(numbers, size);

    return 0;
}

int *initArray(int numbers[], int size)
{
    srand(time(nullptr));
    for (int i{}; i < size; ++i)
    {
        numbers[i] = rand() % 10 + 1;
    }
    return numbers;
}

void printArray(int array[], int size)
{

    cout << "[ ";
    for (int i{}; i < size; ++i)
    {
        cout << (array[i]) << " ";
    }
    cout
        << "]" << endl;
}

void printReversedArray(int array[], int size)
{

    cout << "[ ";
    while (size > 0)
    {
        cout << *(array + size - 1) << " ";
        size--;
    }
    cout
        << "]" << endl;
}