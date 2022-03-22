#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int number{};
    char weekDay[10]{};
    char prefix[3]{};

    do
    {
        cout << "Please enter a number between 1 and 7: ";
        cin >> number;
    } while (number < 1 || number > 7);

    switch (number)
    {
    case 1:
        strcpy(weekDay, "Sunday");
        strcpy(prefix, "st");
        break;
    case 2:
        strcpy(weekDay, "Monday");
        strcpy(prefix, "nd");
        break;
    case 3:
        strcpy(weekDay, "Tuesday");
        strcpy(prefix, "rd");
        break;
    case 4:
        strcpy(weekDay, "Wednesday");
        strcpy(prefix, "th");
        break;
    case 5:
        strcpy(weekDay, "Thursday");
        strcpy(prefix, "th");
        break;
    case 6:
        strcpy(weekDay, "Friday");
        strcpy(prefix, "th");
        break;
    case 7:
        strcpy(weekDay, "Saturday");
        strcpy(prefix, "th");
        break;
    default:
        cout << "Unknow day of Week" << endl;
    }

    cout << "The " << number << prefix << " day of the week is " << weekDay << endl;

    return 0;
}
