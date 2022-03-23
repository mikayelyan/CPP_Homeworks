#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void printArray(int **array, int size);
void fillRandomValues(int **array, int size);
int **initArray(int size);
void calculateAndPrintTriangleTotals(int **array, int size);

int main()
{
    int size{};
    cout << "Please enter a natural number for square matrix's row length: ";
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
            cout << "Wrong input! Please enter number > 0" << endl;
            return 0;
        }
    }

    int **array = initArray(size);
    fillRandomValues(array, size);
    printArray(array, size);
    calculateAndPrintTriangleTotals(array, size);
    return 0;
}

void printArray(int **array, int size)
{
    for (int j{}; j < size; ++j)
    {

        cout << "[ ";
        for (int i{}; i < size; ++i)
        {
            cout << (array[j][i]) << (i != size - 1 ? ", " : " ");
        }
        cout
            << "]" << endl;
    }
}

void fillRandomValues(int **array, int size)
{
    srand(time(nullptr));
    for (int i{}; i < size; ++i)
    {
        for (int k{}; k < size; ++k)
        {
            (array[i][k]) = rand() % 10 + 1;
        }
    }
}

int **initArray(int size)
{
    int **array;
    array = new int *[size];

    for (int i{}; i < size; ++i)
    {
        array[i] = new int[size];
    }
    return array;
}

void calculateAndPrintTriangleTotals(int **array, int size)
{
    int totalTop{};
    int totalLeft{};
    int totalRight{};
    int totalBottom{};
    int totalLeftBottom{};
    int totalLeftTop{};
    int totalRightTop{};
    int totalRightBottom{};
    for (int i{0}; i < size; ++i)
    {
        // Top small triangle
        for (int k{i + 1}; k < size - i - 1; ++k)
        {
            totalTop += array[i][k];
        }
        // Left small triangle
        for (int j{0}; j < i && j < (size - i - 1); ++j)
        {
            totalLeft += array[i][j];
        }
        // Right small triangle
        for (int j{size - 1}; j > i && j > (size - i - 1); --j)
        {
            totalRight += array[i][j];
        }
        // Bottom small triangle
        for (int j{i - 1}; j < i && j > (size - i - 1); --j)
        {
            totalBottom += array[i][j];
        }
        // Left-bottom triangle
        for (int j{0}; j < i; ++j)
        {
            totalLeftBottom += array[i][j];
        }
        // Left-top triangle
        for (int j{size - i - 2}; j >= 0; --j)
        {
            totalLeftTop += array[i][j];
        }
        // Right-top triangle
        for (int j{size - 1}; j > i; --j)
        {
            totalRightTop += array[i][j];
        }
        // Right-bottom triangle
        for (int j{size - 1}; j >= size - i; --j)
        {
            totalRightBottom += array[i][j];
        }
    }
    cout << endl;
    cout << "1.Top: " << totalTop << endl;
    cout << "2.Left: " << totalLeft << endl;
    cout << "3.Right: " << totalRight << endl;
    cout << "4.Bottom: " << totalBottom << endl;
    cout << "5.Left-bottom: " << totalLeftBottom << endl;
    cout << "6.Left-top: " << totalLeftTop << endl;
    cout << "7.Right-top: " << totalRightTop << endl;
    cout << "8.Right-bottom: " << totalRightBottom << endl;
}
