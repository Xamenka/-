//Варіант 2
#include <iostream>
#include <cmath>    // для математичних функцій

using namespace std;

int main() {
    // Задані значення змінних
    double a = 2;
    double b = 14.36;

    //Обчислення необхідних значень
    double ln_a = log(a);            // натуральний логарифм a
    double cbrt_b = cbrt(b);         // кубічний корінь з b
    double cos_b = cos(b);           // косинус b
    double exp_a = exp(a);           // експонента a
    double a_pow_a = pow(a, a);      // a в степені a

    //Обчислення чисельника та знаменника
    double numerator = 8.15 * cbrt_b * ln_a;
    double denominator = 24.38 * cos_b * (exp_a - a_pow_a);

    //Остаточне обчислення y
    double y = numerator / denominator;

    //Виведення результату
    cout << "Значення функції y = " << y << endl;

    return 0;
}
