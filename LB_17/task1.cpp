#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false; // Числа менше 2 не є натуральними 
    for (int i = 2; i * i <= num; i++) { 
        if (num % i == 0) return false; //Якщо ділиться без остатку то не є натуральне 
    }
    return true; // Если не нашли делителей, число простое
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }
    
    return 0;
}