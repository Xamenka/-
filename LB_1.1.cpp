#include <iostream>
#include <cmath>    

using namespace std;

int main() {
    double a = 2;
    double b = 3.141;

    double ln_a = log(a);
    double ln_b = log(b);
    double ln_b_a = log(b / a);

    double part1 = ln_b / 0.711;
    double part2 = ln_b_a / (1 + part1);
    double part3 = cbrt(1 + part2);
    double part4 = cbrt(1 + part3);

    //Îñòàòî÷íå îá÷èñëåííÿ y
    double y = part4 * (ln_a / 0.315);

    //Âèâåäåííÿ ðåçóëüòàòó
    cout << "Çíà÷åííÿ ôóíêö³¿ y = " << y << endl;

    return 0;
}
