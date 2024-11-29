#include <iostream>
#include <cmath>    

using namespace std;

int main() {
    double a = 2;
    double b = 14.36;

    double ln_a = log(a);            // íàòóðàëüíèé ëîãàðèôì a
    double cbrt_b = cbrt(b);         // êóá³÷íèé êîð³íü ç b
    double cos_b = cos(b);           // êîñèíóñ b
    double exp_a = exp(a);           // åêñïîíåíòà a
    double a_pow_a = pow(a, a);      // a â ñòåïåí³ a

  
    double numerator = 8.15 * cbrt_b * ln_a;
    double denominator = 24.38 * cos_b * (exp_a - a_pow_a);

    double y = numerator / denominator;

 
    cout << "Çíà÷åííÿ ôóíêö³¿ y = " << y << endl;

    return 0;
}
