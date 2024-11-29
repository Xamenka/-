#include <iostream>
#include <string>

using namespace std;

int main() {
    int code;

    cout << "Enter a numeric constellation code (1-7): ";
    cin >> code;

    switch (code) {
    case 1:
        cout << "Constellation: Aries\nNumber of stars: 20\n";
        break;
    case 2:
        cout << "Constellation: Taurus\nNumber of stars: 15\n";
        break;
    case 3:
        cout << "Constellation: Gemini\nNumber of stars: 30\n";
        break;
    case 4:
        cout << "Constellation: Cancer\nNumber of stars: 10\n";
        break;
    case 5:
        cout << "Constellation: Leo\nNumber of stars: 25\n";
        break;
    case 6:
        cout << "Constellation: Virgo\nNumber of stars: 18\n";
        break;
    case 7:
        cout << "Constellation: Libra\nNumber of stars: 12\n";
        break;
    default:
        cout << "Invalid code! Please enter a number between 1 and 7.\n";
        break;
    }

    return 0;
}
