#include <iostream> 
#include <iomanip>  

using namespace std;

int main() { 
    int part1, part2, part3, part4;

    cout << "Enter four numbers (each between 1 and 255): ";

    
    cin >> part1 >> part2 >> part3 >> part4;

   
    if ((part1 >= 1 && part1 <= 255) &&
        (part2 >= 1 && part2 <= 255) &&
        (part3 >= 1 && part3 <= 255) &&
        (part4 >= 1 && part4 <= 255)) {

     
        cout << part1 << '.' << part2 << '.' << part3 << '.' << part4 << endl;
    }
    else {
        cout << "Invalid input. Each number must be between 1 and 255." << endl;
    }

    return 0;
}
