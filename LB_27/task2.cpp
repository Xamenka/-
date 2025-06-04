#include <iostream>
using namespace std;

int main(void) {
    int a = 0, b = 0, c = 0;
    
    cout << "Enter two integers (dividend and divisor):\n";
    cin >> a;  // Вводимо чисельник
    cin >> b;  // Вводимо дільник

    try {
        if (b == 0) {
            // Викидаємо виняток, якщо дільник 0
            throw "Your input is not valid, you can't divide by zero.";
        }
        c = a / b;  // Ділення
        cout << "Result: " << c << endl;  // Виведення результату
    }
    catch (const char* msg) {
        // Перехоплюємо виняток та виводимо повідомлення
        cout << msg << endl;
    }

    return 0;
}
