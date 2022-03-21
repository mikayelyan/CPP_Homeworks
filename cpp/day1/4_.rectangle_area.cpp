#include <iostream>
using namespace std;

double getArea(double width, double length);
double getPerimeter(double width, double length);

int main()
{
    double length{};
    double width{};
    double area{};
    double perimeter{};

    cout << "Please enter the length of rectangle: ";
    cin >> length;
    cout << "Please enter the width of rectangle: ";
    cin >> width;

    area = getArea(length, width);
    perimeter = getPerimeter(length, width);

    cout << "The area of rectangle is " << area << endl;
    cout << "The perimeter of rectangle is " << perimeter << endl;

    return 0;
}

double getArea(double width, double length)
{
    return width * length;
}

double getPerimeter(double width, double length)
{
    return 2 * (width + length);
}