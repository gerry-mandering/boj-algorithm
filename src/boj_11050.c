#include <stdio.h>

int fac(int num);

int main(void) {
    int n, k, result;

    scanf("%d %d", &n, &k);

    result = fac(n) / (fac(n-k) * fac(k));
    printf("%d", result);

    return 0;
}

int fac(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * fac(num - 1);
    }
}