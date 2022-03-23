#include <iostream>
#include <cmath>
using namespace std;

void printArray(int[], int);
void fillArray(int[], int);

int main()
{
    int size{10};
    int array[size]{};

    fillArray(array, size);
    printArray(array, size);
    
    return 0;
}

void printArray(int array[], int size)
{

    cout << "[ ";
    for (int i{}; i < size; ++i)
    {
        cout << (array[i]) << (i != size - 1 ? ", " : " ");
    }
    cout
        << "]" << endl;
}

void fillArray(int array[], int size)
{
    int num1{3};
    int num2{4};
    for (int i{}; i < size; ++i)
    {
        array[i] = pow(num1, 2) + pow(num2, 2);
        num1 += 3;
        num2 += 4;
    }
}