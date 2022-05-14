#include <stdio.h>

int main(void) {
    int min=1000001, max=1000001, count, num;

    scanf("%d", &count);

    for (int i=0; i<count; i++) {
        scanf("%d", &num);
        if (min == 1000001 && max == 1000001) {
            min = num;
            max = num;
        } else {
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
    }

    printf("%d ", min);
    printf("%d", max);

    return 0;
}
