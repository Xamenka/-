#include <iostream> 
#include <cmath>   

using namespace std; 

int main() { 
  
    int num1, num2;

    
    cout << "Enter two integers: ";

    cin >> num1 >> num2;

   
        cout << "Division by zero is not allowed." << endl; 
        return 1; 
    }

   
    float reciprocal1 = 1.0f / static_cast<float>(num1);
    float reciprocal2 = 1.0f / static_cast<float>(num2);

   
    const float epsilon = 0.000001f;

  
    if (fabs(reciprocal1 - reciprocal2) < epsilon) {
        cout << "Results are equal (by 0.000001 epsilon)" << endl; 
    }
    else {
        cout << "Results are not equal (by 0.000001 epsilon)" << endl; 
    }

    return 0; 
}
