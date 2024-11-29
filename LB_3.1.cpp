#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a three-digit number: ";
    cin >> N;

    // Отримуємо окремі цифри числа
    int hundreds = N / 100;        // Сотні
    int tens = (N / 10) % 10;      // Десятки
    int units = N % 10;            // Одиниці

    int product = 1;               // Добуток парних цифр
    bool hasEven = false;          // Чи є парні цифри

    // Перевіряємо, чи є цифра парною, і обчислюємо добуток
    if (hundreds % 2 == 0) {
        product *= hundreds;
        hasEven = true;
    }
    if (tens % 2 == 0) {
        product *= tens;
        hasEven = true;
    }
    if (units % 2 == 0) {
        product *= units;
        hasEven = true;
    }

    // Виводимо результат
    if (hasEven) {
        cout << "Product of even digits: " << product << endl;
    }
    else {
        cout << "There are no even digits in the number." << endl;
    }

    return 0;
}
