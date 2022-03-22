#include <iostream>
using namespace std;

void drawTreePosLeft(int);
void drawTreePosRight(int);
void drawTreePosCenter(int);
void drawReversedTreePosLeft(int);
void drawReversedTreePosRight(int);
void drawReversedTreePosCenter(int);

int main()
{
    unsigned int height{0};
    cout << "Please enter a Christmas tree height (natural number): ";
    cin >> height;

    drawTreePosLeft(height);
    drawTreePosRight(height);
    drawTreePosCenter(height);
    drawReversedTreePosLeft(height);
    drawReversedTreePosRight(height);
    drawReversedTreePosCenter(height);

    return 0;
}

void drawTreePosLeft(int height)
{
    cout << "Tree positioned left:" << endl;
    for (int i{}; i < height; ++i)
    {
        for (int k{}; k <= i; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void drawTreePosRight(int height)
{
    cout << "Tree positioned right:" << endl;
    for (int i{}; i < height; ++i)
    {
        for (int j{}; j < height - i - 1; ++j)
        {
            cout << " ";
        }
        for (int k{}; k <= i; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void drawTreePosCenter(int height)
{
    cout << "Christmas tree positioned center:" << endl;
    for (int i{}; i < height; ++i)
    {
        for (int j{}; j < height - i - 1; ++j)
        {
            cout << " ";
        }
        for (int k{}; k <= i; ++k)
        {
            cout << "*";
        }
        for (int k{}; k < i; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void drawReversedTreePosLeft(int height)
{
    cout << "Reversed tree positioned left:" << endl;
    for (int i{}; i < height; ++i)
    {
        for (int k{}; k < height - i; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void drawReversedTreePosRight(int height)
{
    cout << "Reversed tree positioned right:" << endl;
    for (int i{}; i < height; ++i)
    {
        for (int j{}; j < i; ++j)
        {
            cout << " ";
        }
        for (int k{}; k < height - i; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void drawReversedTreePosCenter(int height)
{

    cout << "Reversed Christmas tree positioned center:" << endl;
    for (int i{}; i < height; ++i)
    {
        for (int j{}; j < i; ++j)
        {
            cout << " ";
        }
        for (int k{}; k < height - i; ++k)
        {
            cout << "*";
        }
        for (int k{}; k < height - i - 1; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }
}