#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double sum = 0.0;
    int count = 20;   

    for (int i = 1; i <= count; ++i) {
        sum += sqrt(i); 
    }

   
    double average = sum / count;

   
    cout << "The arithmetic mean of the roots of numbers from 1 to 20: " << average << endl;

    return 0;
}
