#include <iostream>
using namespace std;

int main() {
    double x, z, Y;

    // Введення значень змінних x та z
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Введіть значення z: ";
    cin >> z;

    // Обчислення значення Y залежно від x
    if (x <= 1) {
        Y = (6 * z * z - 5) / 3;
    }
    else {
        Y = (5 * z * z - 4) / 12;
    }

    // Виведення результату
    cout << "Значення Y: " << Y << endl;

    return 0;
}
