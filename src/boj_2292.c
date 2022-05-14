#include <stdio.h>

int main(void) {
    int num, last = 1, count = 1, adder = 6;

    scanf("%d", &num);

    if (num == 1) {
        printf("%d", 1);
    } else {
        while (last < num) {
            last += adder;
            adder += 6;
            count++;
        }
        printf("%d", count);
    }

    return 0;
}