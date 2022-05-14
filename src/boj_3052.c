#include <stdio.h>

int main(void) {
    int rest[10], numArr[42], input, count=0;

    for (int i=0; i<42; i++) {
        numArr[i] = 0;
    }

    for (int i=0; i<10; i++) {
        scanf("%d", &input);
        rest[i] = input % 42;
    }

    for (int i=0 ;i<10; i++) {
        numArr[rest[i]]++;
    }

    for (int i=0; i<42; i++) {
        if (numArr[i] != 0) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}