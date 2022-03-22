#include <iostream>
using namespace std;

int main()
{
    int number{};
    unsigned long long result{1};

    do
    {
        cout << "Please enter a number between 0 and 20: ";
        cin >> number;
    } while (number < 0 || number > 20);

    int initialNumber{number};

    while (number != 0)
    {
        result *= number;
        number--;
    }

    cout << "The factorial of " << initialNumber << " is equal to " << result << endl;

    return 0;
}
