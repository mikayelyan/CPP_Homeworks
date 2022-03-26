#include <iostream>
#include <ctime>
using namespace std;

int sumArrayElements(int numbers[], int size);
int *initArray(int numbers[], int size);
void printArray(int array[], int size);

int main()
{
    int size{10};
    int numbers[size]{};
    initArray(numbers, size);
    int result = sumArrayElements(numbers, size);
    printArray(numbers, size);
    cout << "Result: " << result <<     endl;

    return 0;
}

int sumArrayElements(int numbers[], int size)
{
    int sum{};
    while (size > 0)
    {
        sum += *(numbers + size - 1);
        size--;
    }
    return sum;
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