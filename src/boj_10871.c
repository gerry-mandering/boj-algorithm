#include <stdio.h>

int main(void) {
    int count, key, num;

    scanf("%d", &count);
    scanf("%d", &key);

    for (int i=0; i<count; i++) {
        scanf("%d", &num);
        if (num < key) {
            printf("%d ", num);
        }
    }

    return 0;
}