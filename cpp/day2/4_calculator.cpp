#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int number1{};
    int number2{};
    char operatorSymbol{};
    cout << "Input number: ";
    cin >> number1;
    cout << "Input operator: ";
    cin >> operatorSymbol;
    cout << "Input number: ";
    cin >> number2;

    cout << number1 << " " << operatorSymbol << " " << number2 << " = ";
    switch (operatorSymbol)
    {
    case '+':
        cout << number1 + number2 << endl;
        break;
    case '*':
        cout << number1 * number2 << endl;
        break;
    case '-':
        cout << number1 - number2 << endl;
        break;
    case '/':
        try
        {
            if (number2 == 0)
                throw 0;
            cout << number1 / number2 << endl;
        }
        catch (int &er)
        {
            if (er == 0)
                cout << "Number can't be divided by 0" << endl;
        }
        break;
    default:
        cout << "Wrong operator entered" << endl;
        break;
    }

    return 0;
}
