#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void printMatrix(int **matrix, int size);
void fillRandomValues(int **matrix, int size);
int **initMatrix(int size);
void deallocateMemory(int **matrix, int size);
int **addMatrixes(int **matrixA, int **matrixB, int size);

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
    srand(time(nullptr));

    int **matrixA = initMatrix(size);
    int **matrixB = initMatrix(size);
    int **result = addMatrixes(matrixA, matrixB, size);
    cout << endl
         << "Matrix A:" << endl;
    printMatrix(matrixA, size);
    cout << endl
         << "Matrix B:" << endl;
    printMatrix(matrixB, size);
    cout << endl
         << "Result of addition:" << endl;
    printMatrix(result, size);

    deallocateMemory(matrixA, size);
    deallocateMemory(matrixB, size);
    deallocateMemory(result, size);
    return 0;
}

void printMatrix(int **matrix, int size)
{
    for (int j{}; j < size; ++j)
    {

        cout << "[ ";
        for (int i{}; i < size; ++i)
        {
            cout << (matrix[j][i]) << (i != size - 1 ? ", " : " ");
        }
        cout
            << "]" << endl;
    }
}

void fillRandomValues(int **matrix, int size)
{
    for (int i{}; i < size; ++i)
    {
        for (int k{}; k < size; ++k)
        {
            (matrix[i][k]) = rand() % 10 + 1;
        }
    }
}

int **initMatrix(int size)
{
    int **matrix;
    matrix = new int *[size];

    for (int i{}; i < size; ++i)
    {
        matrix[i] = new int[size];
    }
    fillRandomValues(matrix, size);
    return matrix;
}

void deallocateMemory(int **matrix, int size)
{
    for (int i{}; i < size; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int **addMatrixes(int **matrixA, int **matrixB, int size)
{
    int **result;
    result = new int *[size];

    for (int i{}; i < size; ++i)
    {
        result[i] = new int[size];
        for (int j{}; j < size; ++j)
        {
            result[i][j] = (matrixA[i][j] + matrixB[i][j]);
        }
    }
    return result;
}
