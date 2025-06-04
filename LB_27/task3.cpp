#include <iostream>
using namespace std;

const int DivideByZero = 111;

float internaldiv(float arg1, float arg2)
{
    if (arg2 == 0.0)
        throw DivideByZero; // Throw an exception if division by zero
    return arg1 / arg2;
}

int main(void)
{
    float r, a, b;
    while (cin >> a)
    {
        cin >> b;
        try
        {
            r = internaldiv(a, b); // Try to perform division
            cout << r << endl;      // If successful, print the result
        }
        catch (int e)
        {
            if (e == DivideByZero)
                cout << "Your input is not valid. You can't divide by zero." << endl; // Handle the division by zero error
        }
    }
    return 0;
}
