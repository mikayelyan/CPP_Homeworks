#include <iostream>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

void swapNumbers(int *a, int *b);

int main()
{
    int num1{};
    int num2{};
    cout << "Please enter the number 1: ";
    cin >> num1;
    cout << "Please enter the number 2: ";
    cin >> num2;

    int *num1_ptr{nullptr};
    int *num2_ptr{nullptr};

    num1_ptr = &num1;
    num2_ptr = &num2;

    cout << "Before: number1: " << *num1_ptr << " number2: " << *num2_ptr << endl;
    swapNumbers(num1_ptr, num2_ptr);
    cout << "After: number1: " << *num1_ptr << " number2: " << *num2_ptr << endl;

    return 0;
}

void swapNumbers(int *a, int *b)
{
    int temp{};
    temp = *a;
    *a= *b;
    *b = temp;
}
