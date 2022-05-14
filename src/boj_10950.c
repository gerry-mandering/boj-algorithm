#include <stdio.h>

int main(void) {
    int count, a, b;

    scanf("%d", &count);

    for (int i = 0; i < count; ++i) {
        scanf("%d", &a);
        scanf("%d", &b);
        printf("%d ", a+b);
    }

    return 0;
}