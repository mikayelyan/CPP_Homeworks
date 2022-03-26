#include <iostream>
#include <ctime>
using namespace std;

int *initArray(int numbers[], int size);
void printArray(int array[], int size);
void findMinAndMax(int array[], int size);

int main()
{
    int size{10};
    int numbers[size]{};
    initArray(numbers, size);
    printArray(numbers, size);
    findMinAndMax(numbers, size);

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

void findMinAndMax(int array[], int size)
{
    int min = *array;
    int max = *array;
    while (size > 0)
    {
        if (min > *(array + size - 1))
        {
            min = *(array + size - 1);
        };
        if (max < *(array + size - 1))
        {
            max = *(array + size - 1);
        }
        size--;
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}