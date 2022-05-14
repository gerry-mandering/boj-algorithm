#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int a, b;

    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d ", a+b);
    }

    return 0;
}