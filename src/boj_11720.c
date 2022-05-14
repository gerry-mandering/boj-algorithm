#include <stdio.h>

int main(void) {
    int count, sum=0;
    char num[100];

    scanf("%d", &count);
    scanf("%s", num);

    for (int i=0; i<count; i++) {
        sum += (num[i] - 48);
    }

    printf("%d", sum);
    return 0;
}