#include <stdio.h>

int recursive(int k, int n);

int main(void) {
    int k, n, count;

    scanf("%d", &count);

    for (int i=0; i<count; i++) {
        scanf("%d", &k);
        scanf("%d", &n);

        printf("%d\n", recursive(k, n));
    }

}

int recursive(int k, int n) {
    int sum = 0;

    if (k == 0) {
        return n;
    } else {
        for (int i=1; i<=n; i++) {
            sum += recursive(k-1, i);
        }
        return sum;
    }
}