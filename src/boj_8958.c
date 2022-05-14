#include <stdio.h>
#include <string.h>

int main(void) {
    int size, scoreCount, score=0;
    char check[80];

    scanf("%d", &size);

    for (int i=0; i<size; i++) {
        scanf("%s", check);
        scoreCount = 0;
        for (int j=0; j< strlen(check); j++) {
            if (check[j] == 'O') {
                scoreCount++;
                score += scoreCount;
            } else {
                scoreCount = 0;
            }
        }
        printf("%d\n", score);
        score = 0;
    }

    return 0;
}