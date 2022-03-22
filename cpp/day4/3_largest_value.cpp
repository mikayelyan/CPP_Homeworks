#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

void printArray(const float[], int);
void fillRandomValues(float[], int);
float getLargestValue(const float[], int);

int main()
{
    int size{};
    cout << "Please enter the size of array: ";
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
    printArray(numbers, size);
    float largest = getLargestValue(numbers, size);

    cout << largest << " is the largest number in the array" << endl;

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

float getLargestValue(const float array[], int size)
{
    float largest{array[0]};
    for (int i{}; i < size; ++i)
    {
        if (array[i] > largest)
            largest = array[i];
    }
    return largest;
}
