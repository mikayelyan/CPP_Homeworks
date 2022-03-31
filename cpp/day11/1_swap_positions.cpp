#include <iostream>
#include <ctime>
#include <climits>

using namespace std;

int getNumberLength(int);
int swapPosition(int, int, int, int);
int getPositionValue(int, int, int);
int getPositionFactor(int, int, int);

int main()
{
    int number{};
    int pos1{};
    int pos2{};
    cout << "Input number: ";
    cin >> number;
    cout << "Input positions to swap : ";
    cin >> pos1 >> pos2;

    int length = getNumberLength(number);

    try
    {
        if (number < 10)
            throw 0;
        if (number > INT_MAX)
            throw 1;
        if (pos1 < 1 || pos2 < 1)
            throw 2;
        if (pos1 > length || pos2 > length)
            throw 3;
    }
    catch (int &er)
    {
        if (er == 0)
            cout << "Please enter a number > 10" << endl;
        if (er == 1)
            cout << "Please enter number < " << INT_MAX << endl;
        if (er == 2)
            cout << "Wrong input! Please enter a positive number > 0" << endl;
        if (er == 3)
            cout << "Wrong input! Please enter valid values for positions between 1 and " << length << " " << endl;
        return 1;
    }
    int swapped = swapPosition(number, pos1, pos2, length);
    cout << swapped << endl;
}

int getNumberLength(int number)
{
    int length{};
    while (number != 0)
    {
        number = number / 10;
        length++;
    }
    return length;
}

int swapPosition(int number, int pos1, int pos2, int length)
{
    int pos1Value = getPositionValue(number, pos1, length);
    int factor1 = getPositionFactor(number, pos1, length);
    int pos2Value = getPositionValue(number, pos2, length);
    int factor2 = getPositionFactor(number, pos2, length);
    int swapped = number + factor1 * (pos2Value - pos1Value) + factor2 * (pos1Value - pos2Value);
    return swapped;
}

int getPositionValue(int number, int pos, int length)
{
    for (int i{}; i < length - pos; ++i)
    {
        number /= 10;
    }
    return number % 10;
}

int getPositionFactor(int number, int pos, int length)
{
    int factor{1};
    for (int i{}; i < length - pos; ++i)
    {
        factor *= 10;
    }
    return factor;
}