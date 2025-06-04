#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib> // для exit()
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            cout << "Error: division by zero is not allowed." << endl;
            exit(1);
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        this->numerator = numerator;
        this->denominator = denominator;
    }

    string toString() {
        int wholePart = numerator / denominator;
        int remainder = abs(numerator % denominator);

        if (remainder == 0) {
            return to_string(wholePart);
        }

        if (wholePart == 0) {
            return to_string(numerator) + "/" + to_string(denominator);
        }

        return to_string(wholePart) + " " + to_string(remainder) + "/" + to_string(denominator);
    }

    double toDouble() {
        return (double)numerator / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    int num, den;
    string input;

    cout << "Enter a fraction in the format [numerator] / [denominator]: ";
    getline(cin, input);

    sscanf(input.c_str(), "%d / %d", &num, &den);

    Fraction fraction(num, den);

    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
