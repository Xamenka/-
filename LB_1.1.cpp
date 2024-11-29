// Варіант 22
#include <iostream>
#include <cmath>    // для використання математичних функцій

using namespace std;

int main() {
    // Задане значення змінних
    double a = 2;
    double b = 3.141;

    //Обчислення логарифмів
    double ln_a = log(a);
    double ln_b = log(b);
    double ln_b_a = log(b / a);

    //Обчислення складових всередині формули
    double part1 = ln_b / 0.711;
    double part2 = ln_b_a / (1 + part1);
    double part3 = cbrt(1 + part2);
    double part4 = cbrt(1 + part3);

    //Остаточне обчислення y
    double y = part4 * (ln_a / 0.315);

    //Виведення результату
    cout << "Значення функції y = " << y << endl;

    return 0;
}
