#include <iostream>
using namespace std;

int main()
{
    int number{};
    cout << "Please input a number: ";
    cin >> number;

    cout << "Multiplication table of " << number << endl;
    for (int i{1}; i <= 10; ++i)
    {
        cout << number << " * " << i << " = " << number * i << endl;
    }
}