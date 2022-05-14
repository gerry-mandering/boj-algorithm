#include <stdio.h>
#include <string.h>

int main(void) {
    char word[100];
    int a_to_z[26];

    for (int i=0; i<26; i++) {
        a_to_z[i] = -1;
    }

    scanf("%s", word);

    for (int i=0; i<strlen(word); i++) {
        if(a_to_z[word[i] - 97] == -1) {
            a_to_z[word[i] - 97] = i;
        }
    }

    for (int i=0; i<26; i++) {
        printf("%d ", a_to_z[i]);
    }

    return 0;
}