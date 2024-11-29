#include <iostream>
using namespace std;

bool isInRegion22(double x, double y) {
    // Перевірка, чи точка знаходиться в межах трикутника
    if (x >= 0 && y >= 0 && x + y <= 2) {
        return true;
    }
    return false;
}

int main() {
    double x, y;
    cout << "Enter the coordinates of the point (x, y): ";
    cin >> x >> y;

    if (isInRegion22(x, y)) {
        cout << "The point falls into the shaded area 22." << endl;
    }
    else {
        cout << "The point does not fall within the shaded area 22." << endl;
    }

    return 0;
}
