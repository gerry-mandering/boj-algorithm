#include <stdio.h>

int main(void) {
    int x, y, w, h, min;
    int lengthArr[4];

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &w);
    scanf("%d", &h);

    lengthArr[1] = y;
    lengthArr[2] = w - x;
    lengthArr[3] = h - y;

    min = x;
    for (int i=1; i<4; i++) {
        if (lengthArr[i] < min) {
            min = lengthArr[i];
        }
    }

    printf("%d", min);

    return 0;
}