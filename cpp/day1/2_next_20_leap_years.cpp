#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t timer;
    timer = time(NULL);
    int currentYear{static_cast<int>(timer / (365 * 60 * 60 * 24) + 1970)};
    int count{1};

    cout << "The next 20 leap year are: " << endl;
    while (count <= 20)
    {
        if ((currentYear % 4 == 0 && currentYear % 100 != 0) || currentYear % 400 == 0)
        {
            cout << count << ": " << currentYear << endl;
            count++;
        }
        currentYear++;
    }

    return 0;
}