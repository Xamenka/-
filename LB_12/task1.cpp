#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    
    const int size = 10;
    int vector[size];
    
    for (int *p = vector; p < vector + size; ++p) {
        *p = std::rand() % 100;	//* є вказівником і буде використовуватися для зберігання інформації про місцезнаходження даних типу int. 
    }
    
    std::cout << "Array: ";
    for (int *p = vector; p < vector + size; ++p) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
    
    int *minPtr = vector;
    
    for (int *p = vector + 1; p < vector + size; ++p) {
        if (*p < *minPtr) {
            minPtr = p;
        }
    }
    
    std::cout << "Smallest element: " << *minPtr << std::endl;
    return 0;
}
