#include <stdio.h>
#include <string.h>

int main(void) {
    int count=0, cnt=0;
    char s[20], p[160];

    scanf("%d", &count);

    for (int i=0; i<count; i++) {
        cnt = 0;
        scanf("%d", &cnt);
        scanf("%s", s);
        for (int k=0; k< strlen(s); k++) {
            for (int j=0; j<cnt; j++) {
                printf("%c", s[k]);
            }
        }
        printf("\n");
    }

    return 0;
}