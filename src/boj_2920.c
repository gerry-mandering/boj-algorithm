#include <stdio.h>

int arrayEqual(int result[], int numArr[]);

int main(void) {
    int numArr[8], count, key = 0;
    int ascending[8] = {1,2,3,4,5,6,7,8};
    int descending[8] = {8,7,6,5,4,3,2,1};

    for (int i = 0; i < 8; i++) {
        scanf("%d", &numArr[i]);
    }

    if (arrayEqual(ascending, numArr)) {
        printf("ascending");
    } else if (arrayEqual(descending, numArr)) {
        printf("descending");
    } else {
        printf("mixed");
    }

    return 0;
}

int arrayEqual(int result[], int numArr[]) {
    for (int i=0; i<8; i++) {
        if (result[i] != numArr[i]) {
            return 0;
        }
    }

    return 1;
}