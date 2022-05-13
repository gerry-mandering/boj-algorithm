#include <stdio.h>

int reverse(int num);

int main(void) {
    int num1, num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    num1 = reverse(num1);
    num2 = reverse(num2);

    if (num1 > num2) {
        printf("%d", num1);
    } else {
        printf("%d", num2);
    }

    return 0;
}

int reverse(int num) {
    int result;
    int a, b, c;

    a = num / 100;
    num = num - a * 100;
    b = num / 10;
    num = num - b * 10;
    c = num;

    result = c * 100 + b * 10 + a;

    return result;
}