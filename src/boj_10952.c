#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int a, b;

    while (scanf("%d %d", &a, &b) != EOF) {
        if (a == 0 && b == 0) {
            break;
        }
        printf("%d\n", a+b);
    }

    return 0;
}