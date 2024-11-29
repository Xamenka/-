#include <iostream> 
#include <iomanip>  

using namespace std; 

int main() { 
    double value1, value2, value3, value4, value5;

    cout << "Enter five values: ";

    cin >> value1 >> value2 >> value3 >> value4 >> value5;

    cout << fixed;


    cout << setprecision(1) << value1 << endl;

    
    cout << setprecision(2) << value2 << endl;

   
    cout << setprecision(6) << value3 << endl;

   
    cout << setprecision(2) << value4 << endl;

   
    cout << static_cast<int>(value5) << endl;

    return 0; // Ïîâåðòàºìî 0, ùîá âêàçàòè íà óñï³øíå çàâåðøåííÿ ïðîãðàìè
