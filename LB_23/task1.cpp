#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept> // для винятків

using namespace std;

// Пошук найбільшого спільного дільника (НСД)
int gcd(int a, int b) {
    if (b == 0)
        return abs(a);
    return gcd(b, a % b);
}

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();         // Повертає рядкове представлення дробу
    double toDouble();         // Повертає десяткове представлення дробу

    Fraction plus(Fraction that);    // Додавання
    Fraction minus(Fraction that);   // Віднімання
    Fraction times(Fraction that);   // Множення
    Fraction by(Fraction that);      // Ділення

private:
    int numerator;
    int denominator;
    void reduce();  // Скорочення дробу
};

// Конструктор дробу з перевіркою на поділ на нуль
Fraction::Fraction(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0) {
        cout << "Error: division by zero is not allowed." << endl;
        exit(1); // Завершуємо програму
    }
    reduce(); // Скорочуємо дріб
}

// Метод скорочення дробу
void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    // Забезпечуємо, що знаменник завжди додатній
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Додавання дробів
Fraction Fraction::plus(Fraction that) {
    int num = this->numerator * that.denominator + that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

// Віднімання дробів
Fraction Fraction::minus(Fraction that) {
    int num = this->numerator * that.denominator - that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

// Множення дробів
Fraction Fraction::times(Fraction that) {
    int num = this->numerator * that.numerator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

// Ділення дробів
Fraction Fraction::by(Fraction that) {
    if (that.numerator == 0) {
        cout << "Error: cannot divide by a fraction with numerator zero." << endl;
        exit(1);
    }
    int num = this->numerator * that.denominator;
    int den = this->denominator * that.numerator;
    return Fraction(num, den);
}

// Перетворення дробу у зручний рядковий вигляд
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

// Перетворення дробу у десятковий формат
double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    string input1, input2;
    int n1, d1, n2, d2;

    // Ввід дробів
    cout << "Enter two fractions (example: 3/4 5/6): ";
    cin >> input1 >> input2;

    // Розділення першого дробу
    size_t slash_pos1 = input1.find('/');
    n1 = stoi(input1.substr(0, slash_pos1));
    d1 = stoi(input1.substr(slash_pos1 + 1));

    // Розділення другого дробу
    size_t slash_pos2 = input2.find('/');
    n2 = stoi(input2.substr(0, slash_pos2));
    d2 = stoi(input2.substr(slash_pos2 + 1));

    // Створення об'єктів дробів
    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    // Вивід результатів усіх операцій
    cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
    cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
    cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
    cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

    return 0;
}
