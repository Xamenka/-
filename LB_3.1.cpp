#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a three-digit number: ";
    cin >> N;

    int hundreds = N / 100;        
    int tens = (N / 10) % 10;     
    int units = N % 10;            

    int product = 1;               
    bool hasEven = false;          
  
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

    if (hasEven) {
        cout << "Product of even digits: " << product << endl;
    }
    else {
        cout << "There are no even digits in the number." << endl;
    }

    return 0;
}
