#include <stdio.h>

int main(void) {
    int i=0;
    int arr[9];
    int temp=0, index=0;

    for (i=0; i<9; i++) {
        scanf("%d", &arr[i]);
    }

    for (i=0; i<9; i++) {
        if(arr[i] > temp) {
            temp = arr[i];
            index = i;
        }
    }

    printf("%d\n%d", arr[index], index+1);
}