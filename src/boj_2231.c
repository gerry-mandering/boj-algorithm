#include <stdio.h>

int sumDigitNum(int num);

int main(void) {
    int n, result, exit=0;

    scanf("%d", &n);

    for (int i=1; i<n; i++) {
        result = 0;
        result = i + sumDigitNum(i);
        if (result == n) {
            printf("%d", i);
            exit = 1;
            break;
        }
    }

    if (exit == 0) {
        printf("%d", 0);
    }

    return 0;
}

int sumDigitNum(int num) {
    int sum = 0, temp = num, digit = 0, divider, digitnum = 0;

    while (temp > 0) {
        temp /= 10;
        digit++;
    }

    for (int i=digit; i>0; i--) {
        divider = 1;
        for (int j=0; j<i-1; j++) {
            divider *= 10;
        }
        digitnum = num / divider;
        sum += digitnum;
        num = num - (digitnum * divider);
    }

    return sum;
}