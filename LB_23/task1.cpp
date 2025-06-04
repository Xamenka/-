#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept> // для винятків

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return abs(a);
    return gcd(b, a % b);
}

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();       
    double toDouble();

    Fraction plus(Fraction that);   
    Fraction minus(Fraction that);  
    Fraction times(Fraction that); 
    Fraction by(Fraction that);     

private:
    int numerator;
    int denominator;
    void reduce();  
};

Fraction::Fraction(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0) {
        cout << "Error: division by zero is not allowed." << endl;
        exit(1); // Завершуємо програму
    }
    reduce(); // Скорочуємо дріб
}

void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction Fraction::plus(Fraction that) {
    int num = this->numerator * that.denominator + that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that) {
    int num = this->numerator * that.denominator - that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::times(Fraction that) {
    int num = this->numerator * that.numerator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::by(Fraction that) {
    if (that.numerator == 0) {
        cout << "Error: cannot divide by a fraction with numerator zero." << endl;
        exit(1);
    }
    int num = this->numerator * that.denominator;
    int den = this->denominator * that.numerator;
    return Fraction(num, den);
}

string Fraction::toString() {
    int whole = numerator / denominator;
    int rem = abs(numerator % denominator);
    if (rem == 0) {
        return to_string(whole);
    }
    if (whole != 0) {
        return to_string(whole) + " " + to_string(rem) + "/" + to_string(denominator);
    } else {
        return to_string(numerator) + "/" + to_string(denominator);
    }
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    string input1, input2;
    int n1, d1, n2, d2;

    cout << "Enter two fractions (example: 3/4 5/6): ";
    cin >> input1 >> input2;

    size_t slash_pos1 = input1.find('/');
    n1 = stoi(input1.substr(0, slash_pos1));
    d1 = stoi(input1.substr(slash_pos1 + 1));

    size_t slash_pos2 = input2.find('/');
    n2 = stoi(input2.substr(0, slash_pos2));
    d2 = stoi(input2.substr(slash_pos2 + 1));

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
    cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
    cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
    cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

    return 0;
}
