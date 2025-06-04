#include <iostream>
#include <ctime>

const int SIZE = 5; // Array size

void fillArray(int (*arr)[SIZE]) {
    srand(time(0));
    for (int *p = &arr[0][0]; p <= &arr[SIZE - 1][SIZE - 1]; ++p) {
        *p = rand() % 100; // Fill with random numbers 0-99
    }
}

void printArray(int (*arr)[SIZE]) {
    for (int *p = &arr[0][0]; p <= &arr[SIZE - 1][SIZE - 1]; ++p) {
        std::cout << *p << " ";
        if ((p - &arr[0][0] + 1) % SIZE == 0) std::cout << "\n";
    }
}

void processArray(int (*arr)[SIZE]) {
    int evenCount = 0, oddCount = 0;
    std::cout << "Main diagonal: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << *(arr[i] + i) << " ";
    }
    std::cout << "\nSecondary diagonal: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << *(arr[i] + (SIZE - 1 - i)) << " ";
    }
    std::cout << "\n";
    
    for (int *p = &arr[0][0]; p <= &arr[SIZE - 1][SIZE - 1]; ++p) {
        if (*p % 2 == 0) ++evenCount;
        else ++oddCount;
    }
    
    std::cout << "Even numbers count: " << evenCount << "\n";
    std::cout << "Odd numbers count: " << oddCount << "\n";
}

int main() {
    int array[SIZE][SIZE];
    fillArray(array);
    std::cout << "Array:\n";
    printArray(array);
    processArray(array);
    return 0;
}
