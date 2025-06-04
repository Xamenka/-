#include <iostream>
#include <iomanip>

int main() {
    const int rows = 10, cols = 10;
    int matrix[rows][cols] = {0};
    int *ptr = &matrix[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(ptr + i * cols + j) = (i + 1) * (j + 1);
        }
    }
    
    std::cout << "Multiplication Table:\n";
    for (int *p = ptr; p < ptr + rows * cols; ++p) {
        std::cout << std::setw(4) << *p;
        if ((p - ptr + 1) % cols == 0) {
            std::cout << std::endl;
        }
    }
    
    return 0;
}
