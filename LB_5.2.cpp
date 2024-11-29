#include <iostream>
#include <cmath> // для функції sqrt

using namespace std;

int main() {
    double sum = 0.0; // Сума квадратних коренів
    int count = 20;   // Кількість чисел

    // Цикл для обчислення суми квадратних коренів
    for (int i = 1; i <= count; ++i) {
        sum += sqrt(i); // Додаємо квадратний корінь до суми
    }

    // Обчислюємо середнє арифметичне
    double average = sum / count;

    // Виводимо результат
    cout << "The arithmetic mean of the roots of numbers from 1 to 20: " << average << endl;

    return 0;
}
