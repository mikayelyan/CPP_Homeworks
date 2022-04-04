#include <iostream>
#include <ctime>
#include <climits>
#include <cmath>

using namespace std;

bool isLeapYear(int);
int getCurrentYear(long *);
string getCurrentMonth(long *, int);
int getCurrentDay(long *);
int getCurrentHour(long *);
int getCurrentMinutes(long *);

int main()
{
    long input{};
    int utc = 4;
    cout << "Please enter a UNIX format date: ";
    cin >> input;
    input += utc * 60 * 60;
    int currentYear = getCurrentYear(&input);
    string currentMonth = getCurrentMonth(&input, currentYear);
    int currentDay = getCurrentDay(&input);
    int currentHour = getCurrentHour(&input);
    int currentMinutes = getCurrentMinutes(&input);

    cout << currentMonth << " "
         << currentDay << " "
         << currentYear << " "
         << currentHour << ":"
         << currentMinutes
         << endl;
    return 0;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getCurrentYear(long *unixTime)
{
    int yearlyUnix = 365 * 24 * 60 * 60;
    int year{1970};
    if (*unixTime > yearlyUnix)
    {
        while (*unixTime > yearlyUnix)
        {
            year++;
            *unixTime -= isLeapYear(year) ? 366 * 24 * 60 * 60 : yearlyUnix;
        }
    }
    return year;
}

string getCurrentMonth(long *unixTime, int year)
{
    int maxMonthUnix = 31 * 24 * 60 * 60;
    int minMonthUnix = 28 * 24 * 60 * 60;
    int month{1};
    if (*unixTime > maxMonthUnix)
    {
        while (*unixTime > minMonthUnix)
        {
            month++;
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                *unixTime -= maxMonthUnix;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                *unixTime -= 30 * 24 * 60 * 60;
                break;
            case 2:
                *unixTime -= isLeapYear(year) ? (29 * 24 * 60 * 60) : minMonthUnix;
                break;
            default:
                break;
            }
        }
    }

    string monthName{"Jan"};
    switch (month)
    {
    case 1:
        return "Jan";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Apr";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "Jun";
        break;
    case 7:
        return "Jul";
        break;
    case 8:
        return "Aug";
        break;
    case 9:
        return "Sep";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    case 12:
        return "Dec";
        break;
    default:
        return "Jan";
        break;
    }

    return monthName;
}

int getCurrentDay(long *unixTime)
{
    int dayUnix = 24 * 60 * 60;
    int day = (*unixTime / dayUnix) + 1;
    *unixTime %= dayUnix;
    return day;
}

int getCurrentHour(long *unixTime)
{
    int hourUnix = 60 * 60;
    int hour = *unixTime / hourUnix;
    *unixTime %= hourUnix;
    return hour;
}

int getCurrentMinutes(long *unixTime)
{
    int minuteUnix = 60;
    int minutes = *unixTime / minuteUnix;
    *unixTime %= minuteUnix;
    return minutes;
}