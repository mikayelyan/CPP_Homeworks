#include <iostream>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

void printMatrix(int **matrix, int size);
int **initMatrix(int size);
void deallocateMemory(int **matrix, int size);
void drawSpiral(int **matrix, int size, int cycle, int number);
int getDigitsCount(int number);

int main()
{
    int size{};
    cout << "Please enter the length of spiral: ";
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

    int **matrix = initMatrix(size);
    cout << endl
         << "Spiral:" << endl;
    drawSpiral(matrix, size, 0, 1);
    printMatrix(matrix, size);
    deallocateMemory(matrix, size);
    return 0;
}

void printMatrix(int **matrix, int size)
{

    int maxValue = pow(size, 2);
    int maxSpaces = getDigitsCount(maxValue);
    for (int j{}; j < size; ++j)
    {
        for (int i{}; i < size; ++i)
        {
            cout << (matrix[j][i]);
            int aa = getDigitsCount(matrix[j][i]);
            for (int i{}; i <= (maxSpaces - aa); ++i)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int **initMatrix(int size)
{
    int **matrix;
    matrix = new int *[size];

    for (int i{}; i < size; ++i)
    {
        matrix[i] = new int[size]{};
    }
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

void drawSpiral(int **matrix, int size, int cycle, int number)
{
    while (number <= (pow(size, 2)))
    {

        for (int j{cycle}; j < size - cycle; ++j)
        {
            matrix[cycle][j] = number;
            number++;
        }
        for (int j{cycle + 1}; j < size - cycle; ++j)
        {
            matrix[j][size - cycle - 1] = number;
            number++;
        }
        for (int j{size - cycle - 2}; j > cycle; --j)
        {
            matrix[size - cycle - 1][j] = number;
            number++;
        }
        for (int j{size - cycle - 1}; j > cycle; --j)
        {
            matrix[j][cycle] = number;
            number++;
        }
        cycle += 1;
        drawSpiral(matrix, size, cycle, number);
    }
}

int getDigitsCount(int number)
{
    int digits{};
    while (number != 0)
    {
        number /= 10;
        digits++;
    }
    return digits;
}
