#include <iostream>
using namespace std;

int main() {
    double x, z, Y;

    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Ââåä³òü çíà÷åííÿ z: ";
    cin >> z;

    if (x <= 1) {
        Y = (6 * z * z - 5) / 3;
    }
    else {
        Y = (5 * z * z - 4) / 12;
    }

    cout << "Çíà÷åííÿ Y: " << Y << endl;

    return 0;
}
