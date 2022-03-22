#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char letter{};
    do
    {
        cout << "Please enter an alphabet letter: ";
        cin >> letter;
    } while (!isalpha(letter));

    switch (tolower(letter))
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
         cout << "'" << letter << "'" << " is a vowel" << endl;
        break;
    case 'y':
    case 'w':
         cout << "'" << letter << "'" << " represents both vowel and consonant sounds" << endl;;
        break;
    default:
        cout << "'" << letter << "'" << " is a consonant" << endl;
        break;
    }

    return 0;
}
