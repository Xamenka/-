#include <iostream> 
#include <iomanip>  

using namespace std;

int main() { 
    // Оголошуємо змінні для зберігання чотирьох частин IP-адреси
    int part1, part2, part3, part4;

    // Виводимо запит до користувача для введення чотирьох чисел
    cout << "Enter four numbers (each between 1 and 255): ";

    // Зчитуємо чотири числа, введені користувачем
    cin >> part1 >> part2 >> part3 >> part4;

    // Перевіряємо, чи всі введені числа знаходяться в діапазоні від 1 до 255
    if ((part1 >= 1 && part1 <= 255) &&
        (part2 >= 1 && part2 <= 255) &&
        (part3 >= 1 && part3 <= 255) &&
        (part4 >= 1 && part4 <= 255)) {

        // Якщо всі числа валідні, виводимо їх як IP-адресу, розділену крапками
        cout << part1 << '.' << part2 << '.' << part3 << '.' << part4 << endl;
    }
    else {
        // Якщо хоча б одне число не відповідає умові, виводимо повідомлення про помилку
        cout << "Invalid input. Each number must be between 1 and 255." << endl;
    }

    return 0; // Повертаємо 0, що означає успішне завершення програми
}