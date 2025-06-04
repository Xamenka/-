#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); 
    
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    
    double* arr = new double[size]; 
    
    int positiveCount = 0, negativeCount = 0;
    
    std::cout << "Generated array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = -2.0 + static_cast<double>(std::rand()) / RAND_MAX * 4.0; 
        std::cout << arr[i] << " ";
        
        if (arr[i] > 0) positiveCount++;
        else if (arr[i] < 0) negativeCount++;
    }
    std::cout << std::endl;
    
    std::cout << "Number of positive numbers: " << positiveCount << std::endl;
    std::cout << "Number of negative numbers: " << negativeCount << std::endl;
    
    delete[] arr; // Звільнення пам'яті
    
    return 0;
}
