#include <stdio.h>

int main(void) {
    int a, b, c, result, num, digit=0, divider;
    int numArr[10];

    for (int i=0; i<10; i++) {
        numArr[i] = 0;
    }

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    result = a * b * c;

    while (result > 0) {
        result /= 10;
        digit++;
    }

    result = a * b * c;

    for (int i=digit; i>0; i--) {
        divider =1;
        for (int j=0; j<i-1; j++) {
            divider *= 10;
        }
        num = result / divider;
        result = result - (num * divider);
        numArr[num]++;
    }

    for (int i=0; i<10; i++) {
        printf("%d\n", numArr[i]);
    }

    return 0;
}