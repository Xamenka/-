#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Оголошення функції для обчислення y
double func(double x) {
    return pow(x, 5) - sqrt(9 - x * x);
}

int main() {
    double a, b, h;

    // Введення початкових значень з клавіатури
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter h: ";
    cin >> h;

    // Перевірка на правильність введення
    if (a > b) {
        cout << "The starting point cannot be greater than the ending point!" << endl;
        return 1;
    }

    cout << "-----------------------" << endl;
    cout << "|   X   |     Y       |" << endl;
    cout << "-----------------------" << endl;

    // Цикл для табулювання значень
    for (double x = a; x <= b; x += h) {
        // Перевірка на область визначення функції
        if (x < -3 || x > 3) {
            cout << "x = " << x << " does not belong to the ODZ!" << endl;
            break;
        }

        // Виведення результатів у вигляді таблиці
        cout << "| " << setw(5) << x << " | " << setw(10) << func(x) << " |" << endl;
    }

    cout << "-----------------------" << endl;

    return 0;
}
