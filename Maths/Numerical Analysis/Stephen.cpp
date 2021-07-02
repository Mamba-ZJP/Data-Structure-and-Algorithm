#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define db double
const db diff = 1e-8;

// x^2 -3x + 2 - e^x = 0
// x^3 + 2x^2 + 10x - 20 = 0

// db func(db x) {
//     return (-pow(x, 3) - 2 * pow(2, x) + 20) / 10;
// }

db func(db x) {
    return (x * x + 2 - exp(x)) / 3;
}

int main(void) {
    // 初始解都为1
    db x = 1.0, y = func(x), z = func(y);
    db k = pow((y - x), 2) / (z - 2 * y + x);
    x = x - k;
    int n = 1;
    while (abs(k) > diff) {
        y = func(x), z = func(y);
        k = pow((y - x), 2) / (z - 2 * y + x);
        x = x - k;
        n++;
    }
    printf("The final answer is %.10f  iteration time is %d", x, n);
    return 0;
}
