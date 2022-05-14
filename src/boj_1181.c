#include <stdio.h>
#include <string.h>

int main(void) {
    int count=0, num=0, n, sixCounter;
    char number[10];

    scanf("%d", &n);

    while (count < n) {
        sixCounter = 0;
        num++;
        sprintf(number, "%d", num);
        for (int i=0; i<strlen(number); i++) {
            if (sixCounter == 0 && number[i] == '6') {
                sixCounter++;
            } else if (number[i-1] == '6' && number[i] == '6') {
                sixCounter++;
                if (sixCounter == 3) {
                    count++;
                    break;
                }
            } else {
                sixCounter = 0;
            }
        }
    }

    printf("%d", num);

    return 0;
}