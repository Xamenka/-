#include <iostream>
using namespace std;

void increment(int &var) {  // var посилання на змінну          
    var += 1; 
}

void increment(int &var, int value) {   // коли збільшуєм var в функції ми змінюємо зміну яку ми передали а не її копію 
    var += value; 
}

int main() {
    int var = 0;                            //якщо кратне + це число , якщо не кратне + 1
    for (int i = 0; i < 10; i++) {
        if (i % 2)
            increment(var);
        else
            increment(var, i);
    }
    cout << var << endl; 
    return 0;
}
