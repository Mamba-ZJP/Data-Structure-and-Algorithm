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
    db x = 1.0, k = 0.0, y = 2.0;
    int cnt = 0;
    while (abs(y - x) > diff) {
        y = x, x = func(x);
        cnt++;
    }
    printf("最终解为 %.10f 迭代次数为 %d", x, cnt);
    return 0;
}