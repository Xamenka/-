#include <iostream>  
#include <cmath>     

using namespace std;  

int main() {  
    double x, y;  
    cout << "Enter five values of x: ";  
    for (int i = 0; i < 5; i++) {  
        cin >> x;  
        y = pow(sin(x), 5) * x + 5 * x - 1.5;  
        cout << "y = " << y << endl; 
    }
    return 0; 
}
