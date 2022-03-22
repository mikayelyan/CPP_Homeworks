#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

void printArray(const float[], int);
void fillRandomValues(float[], int);
void sortArrayDescending(float[], int);

int main()
{
    int size{};
    cout << "Please enter the size of the array: ";
    cin >> size;

    try
    {
        if (size < 1)
            throw 0;
    }
    catch (int &er)
    {
        if (er == 0)
        {

            cout << "Wrong input. Please enter a natural number." << endl;
            return 0;
        }
    }

    float numbers[size]{0};

    fillRandomValues(numbers, size);
    cout << "Before: ";
    printArray(numbers, size);
    sortArrayDescending(numbers, size);
    cout << "After : ";
    printArray(numbers, size);

    return 0;
}

void printArray(const float array[], int size)
{
    cout << "[ ";
    for (int i{}; i < size; ++i)
    {
        cout << array[i] << (i != size - 1 ? ", " : " ");
    }
    cout
        << "]" << endl;
}

void fillRandomValues(float array[], int size)
{
    srand(time(nullptr));

    float max = -100;
    float min = 100;
    for (int i{}; i < size; ++i)
    {
        array[i] = round((min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)))) * 100.0) / 100.0;
    }
}

void sortArrayDescending(float array[], int size)
{
    float temp{};
    for (int i{}; i < size; ++i)
    {
        for (int k{}; k < size - i - 1; ++k)
        {

            if (array[k] < array[k + 1])
            {
                temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
            }
        }
    }
}
