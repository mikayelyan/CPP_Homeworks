#include <iostream>
#include <ctime>
#include <climits>

using namespace std;

bool isPerpendicular(int[]);

int main()
{
    int points[8]{0};
    for (int i{}; i < 8; i += 2)
    {
        cout << "Input coordinates for point " << (char)(65 + i / 2) << ": ";
        cin >> points[i] >> points[(i + 1)];
    }

    cout << boolalpha << isPerpendicular(points) << endl;
}

bool isPerpendicular(int points[])
{
    int lineACoefX = points[0] - points[2];
    int lineACoefY = points[1] - points[3];
    int lineBCoefX = points[4] - points[6];
    int lineBCoefY = points[5] - points[7];

    if (lineACoefY == 0 && lineBCoefX == 0)
        return true;
    if (lineACoefY != 0 && lineBCoefY != 0)
        return (lineACoefX / lineACoefY * lineBCoefX / lineBCoefY) == -1;
    return false;
}
