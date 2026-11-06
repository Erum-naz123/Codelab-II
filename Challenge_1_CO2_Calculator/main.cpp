// Challenge 1: CO2 Calculator
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

double getDistance() {
    double miles;
    while (true) {
        cout << "Journey distance in miles: ";
        if (cin >> miles && miles >= 0) return miles;
        cout << "Please enter a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char getFuelType() {
    char fuel;
    while (true) {
        cout << "Fuel type (P for petrol, D for diesel): ";
        if (cin >> fuel && (fuel == 'P' || fuel == 'p' || fuel == 'D' || fuel == 'd'))
            return fuel;
        cout << "Please enter P or D.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double calculateEmissions(double miles, char fuel) {
    const double litresPer100Miles = 9.66;
    const double dieselKgPerLitre = 2.68;
    const double petrolKgPerLitre = 2.31;
    double litresUsed = miles * litresPer100Miles / 100.0;
    bool isDiesel = (fuel == 'D' || fuel == 'd');
    return litresUsed * (isDiesel ? dieselKgPerLitre : petrolKgPerLitre);
}

int main() {
    cout << "=== Car Journey CO2 Calculator ===\n";
    double miles = getDistance();
    char fuel = getFuelType();
    cout << fixed << setprecision(2);
    cout << "Estimated CO2 emissions: " << calculateEmissions(miles, fuel)
         << " kg CO2\n";
    return 0;
}
