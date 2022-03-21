#include <iostream>
using namespace std;

int animalLegsCounter(int, int, int);

int main()
{
    int chickens{};
    int cows{};
    int pigs{};
    int totalLegs{};

    cout << "Please enter the total number of chickens: ";
    cin >> chickens;
    cout << "Please enter the total number of cows: ";
    cin >> cows;
    cout << "Please enter the total number of pigs: ";
    cin >> pigs;

    totalLegs = animalLegsCounter(chickens, cows, pigs);
    cout << "We have counted total of " << totalLegs << " legs for all animals" << endl;

    return 0;
}

int animalLegsCounter(int totalChickens, int totalCows, int totalPigs)
{
    return 2 * totalChickens + 4 * (totalCows + totalPigs);
}