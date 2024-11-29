#include <iostream>

using namespace std;

int main() {
    int N, digit, sum = 0;

    // Введення числа N з клавіатури
    cout << "Enter a positive integer N: ";
    cin >> N;

    // Розклад числа на цифри та знаходження суми цифр, більших за 5
    while (N > 0) {
        digit = N % 10;  // Отримуємо останню цифру
        if (digit > 5) {
            sum += digit;  // Якщо цифра більше 5, додаємо її до суми
        }
        N /= 10;  // Видаляємо останню цифру
    }

    // Виведення результату
    cout << "The sum of digits greater than 5: " << sum << endl;

    return 0;
}
