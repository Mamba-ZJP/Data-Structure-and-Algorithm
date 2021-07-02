#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define db double
const db diff = 1e-8;

db f(db x) {
    return pow(x, 2) - 3 * x + 2 - exp(x);
}

db fdao(db x) {
    return 2 * x - 3 - exp(x);
}

// db f(db x) {
//     return pow(x, 3) + 2 * pow(x, 2) + 10 * x - 20;
// }

// db fdao(db x) {
//     return 3 * pow(x, 2) + 4 * x + 10;
// }

int main(void) {
    db x = 1, k = f(x) / fdao(x);
    x = x - k;
    int n = 1;
    while (abs(k) > diff) {
        k = f(x) / fdao(x);
        x = x - k, n++;
    }
    printf("最终解为 %.10f 迭代次数为 %d", x, n);
    return 0;
}
