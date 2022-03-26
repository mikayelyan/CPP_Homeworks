#include <iostream>
#include <ctime>
using namespace std;

int **initMatrix(int row, int col);
void fillRandomValues(int **array, int row, int col);
void sortColums(int **array, int row, int col);
void printMatrix(int **array, int row, int col);
void deallocateMemory(int **matrix, int size);

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
            cout << "Wrong input! Please enter a number > 0" << endl;
            return 0;
        }
    }

    int **array = initMatrix(row, col);
    cout << "Before sorting: " << endl;
    printMatrix(array, row, col);
    cout << endl << "After sorting: " << endl;
    sortColums(array, row, col);
    printMatrix(array, row, col);
    deallocateMemory(array, row);
}

int **initMatrix(int row, int col)
{
    int **array;
    array = new int *[row];

    for (int i{}; i < row; ++i)
    {
        array[i] = new int[col];
    }
    fillRandomValues(array, row, col);
    return array;
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

void sortColums(int **array, int row, int col)
{
    int colIndex{};
    while (colIndex < col)
    {
        int rowIndex{row};
        while (rowIndex >= 0)
        {
            int current = rowIndex;
            while (current < row - 1)
            {
                if (*(*(array + current) + colIndex) > *(*(array + current + 1) + colIndex))
                {
                    int temp;
                    temp = *(*(array + current) + colIndex);
                    *(*(array + current) + colIndex) = *(*(array + current + 1) + colIndex);
                    *(*(array + current + 1) + colIndex) = temp;
                }
                current++;
            }
            rowIndex--;
        }
        colIndex++;
    }
}

void printMatrix(int **array, int row, int col)
{
    int rowIndex{};
    while (rowIndex < row)
    {
        cout << "[ ";
        int colIndex{};
        while (colIndex < col)
        {
            cout << *(*(array + rowIndex) + colIndex) << " ";
            colIndex++;
        }
        cout << "]" << endl;
        rowIndex++;
    }
}

void deallocateMemory(int **matrix, int size)
{
    for (int i{}; i < size; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
