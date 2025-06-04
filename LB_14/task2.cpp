#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); 
    
    const int rows = 3, cols = 3;
    int** matrix = new int*[rows]; 
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]; 
    }
    
    int evenCount = 0, oddCount = 0;
    
    std::cout << "Generated matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = std::rand() % 100; 
            std::cout << matrix[i][j] << " ";
            
            if (matrix[i][j] % 2 == 0) evenCount++;
            else oddCount++;
        }
        std::cout << std::endl;
    }
    
    std::cout << "Main diagonal: ";
    for (int i = 0; i < rows; i++) {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Secondary diagonal: ";
    for (int i = 0; i < rows; i++) {
        std::cout << matrix[i][cols - i - 1] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Number of even numbers: " << evenCount << std::endl;
    std::cout << "Number of odd numbers: " << oddCount << std::endl;
    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; 
    }
    delete[] matrix; 
    
    return 0;
}
