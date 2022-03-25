#include <iostream>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

void sum1(int *a, int *b, int *sum);
void sum2(int &a, int &b, int &sum);
void sum3(int a, int b, int &sum);
void sum4(int a, int *b, int &sum);
void sum5(int *a, int *b, int &sum);

int main()
{
    int num1{};
    int num2{};
    cout << "Please enter the number 1: ";
    cin >> num1;
    cout << "Please enter the number 2: ";
    cin >> num2;
    int sum{};
    int *num1_ptr{nullptr};
    int *num2_ptr{nullptr};
    int *sum_ptr{nullptr};

    num1_ptr = &num1;
    num2_ptr = &num2;
    sum_ptr = &sum;

    sum1(num1_ptr, num2_ptr, sum_ptr);
    cout << "sum1: " << *sum_ptr << endl;

    sum2(num1, num2, sum);
    cout << "sum2: " << sum << endl;

    sum3(num1, num2, sum);
    cout << "sum3: " << sum << endl;

    sum4(num1, num2_ptr, sum);
    cout << "sum4: " << sum << endl;

    sum5(num1_ptr, num2_ptr, sum);
    cout << "sum5: " << sum << endl;

    return 0;
}

void sum1(int *a, int *b, int *sum)
{
    *sum = *a + *b;
}
void sum2(int &a, int &b, int &sum)
{
    sum = a + b;
}
void sum3(int a, int b, int &sum)
{
    sum = a + b;
}
void sum4(int a, int *b, int &sum)
{
    sum = a + *b;
}
void sum5(int *a, int *b, int &sum)
{
    sum = *a + *b;
}