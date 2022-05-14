#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
    char num[5];
    int key=0;

    while (scanf("%s", num) != EOF) {
        if (num[0] == '0') {
            break;
        }
        if (strlen(num) == 1) {
            printf("yes\n");
        } else {
            for (int i=0; i< strlen(num)/2; i++) {
                if (num[i] != num[strlen(num)-i-1]) {
                    printf("no\n");
                    key = 1;
                    break;
                }
            }
            if (key == 0) {
                printf("yes\n");
            }
            key = 0;
        }
    }

    return 0;
}