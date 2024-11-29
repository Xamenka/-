#include <iostream>

using namespace std;

int main() {
    int N, digit, sum = 0;

   
    cout << "Enter a positive integer N: ";
    cin >> N;

  
    while (N > 0) {
        digit = N % 10;  
        if (digit > 5) {
            sum += digit;  
        }
        N /= 10;  
    }

  
    cout << "The sum of digits greater than 5: " << sum << endl;

    return 0;
}
