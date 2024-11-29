#include <iostream> 
#include <iomanip>  

using namespace std; 

int main() { 
    // Оголошуємо п'ять змінних типу double для зберігання введених значень
    double value1, value2, value3, value4, value5;

    // Виводимо запит до користувача на введення п'яти значень
    cout << "Enter five values: ";

    // Зчитуємо п'ять значень, введених користувачем, і зберігаємо їх у відповідні змінні
    cin >> value1 >> value2 >> value3 >> value4 >> value5;

    // Встановлюємо фіксований формат виводу для чисел з плаваючою комою
    cout << fixed;

    // Виводимо value1 з однією десятковою цифрою
    cout << setprecision(1) << value1 << endl;

    // Виводимо value2 з двома десятковими цифрами
    cout << setprecision(2) << value2 << endl;

    // Виводимо value3 з шістьма десятковими цифрами
    cout << setprecision(6) << value3 << endl;

    // Виводимо value4 з двома десятковими цифрами (округлене)
    cout << setprecision(2) << value4 << endl;

    // Виводимо value5 як ціле число, кастуючи його до int для видалення дробової частини
    cout << static_cast<int>(value5) << endl;

    return 0; // Повертаємо 0, щоб вказати на успішне завершення програми