#include <iostream>

using namespace std;

int main()
{
    unsigned int number{0};

    cout << "Please enter a natural number: ";
    cin >> number;
    try {
        if(number <= 0 ) {
            throw 0;
        }
    } catch (int &er) {
        if(er == 0) {
            cout << "Invalid input. Plese try again and input a natural number." << endl;
            return 0;
        }
    }
    int binary[number]{0};
    int index{};
    do
    {
        if (number % 2 != 0)
        {
            binary[index] = 1;
        }
        else
        {
            binary[index] = 0;
        }
        number /= 2;
        index++;
    } while (number != 0);

    for (int i{index}; i >= 0; --i)
    {
        cout << binary[i];
    }

    cout << endl;

    return 0;
}
