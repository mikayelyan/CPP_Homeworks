#include <iostream>
using namespace std;

bool isPerfectNumber(unsigned long long);

int main()
{
    unsigned long long number{0};
    cout << "Please enter a natural number: ";
    cin >> number;
    bool isPerfect{false};
    isPerfect = isPerfectNumber(number);
    cout << number << " is " << (isPerfect ? "a" : "not a")
         << " perfect number." << endl;

    return 0;
}

bool isPerfectNumber(unsigned long long num)
{
    unsigned long long currentMaxDivider = num;
    unsigned long long result{1};
    for (unsigned long long i{2}; i < currentMaxDivider; ++i)
    {
        if (num % i == 0)
        {
            result += (i + num / i);
            currentMaxDivider = num / i;
        }
    }
    return num == result;
}