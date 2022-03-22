#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    short number{};
    short numberOfDays{};

    do
    {
        cout << "Please enter a month number between 1 and 12: ";
        cin >> number;
    } while (number < 1 || number > 12);

    switch (number)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays = 31;
        break;
    case 2:
        numberOfDays = 28;
        break;
    default:
        break;
    }

    cout << "Total number of days = " << numberOfDays;
    cout << ((number == 2) ? " (29 if year is leap)" : "") << endl;

    return 0;
}
