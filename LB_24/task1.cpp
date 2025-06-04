#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
    bool isGreaterThan(Fraction that);
    bool isLessThan(Fraction that);
    bool isEqual(Fraction that);

private:
    int numerator;
    int denominator;
    void reduce();
    int gcd(int a, int b);
};

int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    reduce();
}

void Fraction::reduce() {
    int divisor = gcd(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;
    // Упорядковуємо знак: мінус завжди у чисельнику
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

string Fraction::toString() {
    if (abs(numerator) >= denominator) {
        int whole = numerator / denominator;
        int remainder = abs(numerator % denominator);
        if (remainder == 0) return to_string(whole);
        return to_string(whole) + " " + to_string(remainder) + "/" + to_string(denominator);
    }
    return to_string(numerator) + "/" + to_string(denominator);
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

bool Fraction::isGreaterThan(Fraction that) {
    return this->toDouble() > that.toDouble();
}

bool Fraction::isLessThan(Fraction that) {
    return this->toDouble() < that.toDouble();
}

bool Fraction::isEqual(Fraction that) {
    return this->toDouble() == that.toDouble();
}

int main() {
    int num1, den1, num2, den2;
    char slash;
    cin >> num1 >> slash >> den1;
    cin >> num2 >> slash >> den2;
    
    Fraction frac1(num1, den1);
    Fraction frac2(num2, den2);
    
    cout << frac1.toString() << " ";
    if (frac1.isGreaterThan(frac2))
        cout << ">";
    else if (frac1.isLessThan(frac2))
        cout << "<";
    else
        cout << "=";
    
    cout << " " << frac2.toString() << endl;
    return 0;
}
