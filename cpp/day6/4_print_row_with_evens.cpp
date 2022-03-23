#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;

void printArray(int **array, int row, int col);
void fillRandomValues(int **array, int row, int col);
int **initArray(int row, int col);
int getRowWithEvensOnly(int **array, int row, int col);

int main()
{
    int row{};
    int col{};
    cout << "Please enter the size of matrix rows: ";
    cin >> row;
    cout << "Please enter the size of matrix colums: ";
    cin >> col;

    try
    {
        if (row < 1 || col < 1)
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

    int **array = initArray(row, col);
    fillRandomValues(array, row, col);
    printArray(array, row, col);
    
    int rowIndex{};
    try
    {
        rowIndex = getRowWithEvensOnly(array, row, col);
        cout << "row " << rowIndex << " contains only even numbers." << endl;
    }
    catch (int &er)
    {
        if (er == 0)
        {
            cout << "No։" << endl;
        }
    }

    for (int i{}; i < row; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}

void printArray(int **array, int row, int col)
{
    for (int j{}; j < row; ++j)
    {

        cout << "[ ";
        for (int i{}; i < col; ++i)
        {
            cout << (array[j][i]) << (i != col - 1 ? ", " : " ");
        }
        cout
            << "]" << endl;
    }
}

void fillRandomValues(int **array, int row, int col)
{
    srand(time(nullptr));
    for (int i{}; i < row; ++i)
    {
        for (int k{}; k < col; ++k)
        {
            (array[i][k]) = rand() % 100 + 1;
        }
    }
}

int **initArray(int row, int col)
{
    int **array;
    array = new int *[row];

    for (int i{}; i < row; ++i)
    {
        array[i] = new int[col];
    }
    return array;
}

int getRowWithEvensOnly(int **array, int row, int col)
{
    int rowIndex{0};
    bool isAvailable{false};
    for (int i{}; i < row; ++i)
    {
        isAvailable = true;
        for (int j{}; j < col; ++j)
        {
            if (array[i][j] % 2 != 0)
            {
                isAvailable = false;
            }
        }
        rowIndex = i;
        if (isAvailable)
        {
            return rowIndex;
        }
    }

    throw 0;
}