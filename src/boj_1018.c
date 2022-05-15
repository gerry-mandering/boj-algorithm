#include <stdio.h>
#include <stdlib.h>

int countingW(char** board, int n, int m);
int countingB(char** board, int n, int m);

int main(void) {
    int n, m, min, wCount, bCount;
    char **board;

    scanf("%d %d", &n, &m);

    board = (int**) malloc ( sizeof(int*) * n );
    for(int i=0; i<n; i++){
        board[i] = (int*) malloc ( sizeof(int) * m );
    }

    for (int i=0; i<n; i++) {
        scanf("%s", board[i]);
    }

    for (int i=0; i<n-8+1; i++) {
        for (int j=0; j<m-8+1; j++) {
            wCount = countingW(board, i, j);
            bCount = countingB(board, i, j);
            if (i == 0 && j == 0) {
                min = wCount <= bCount ? wCount : bCount;
            } else {
                if ((wCount <= bCount ? wCount : bCount) < min) {
                    min = wCount <= bCount ? wCount : bCount;
                }
            }
        }
    }

    printf("%d", min);

    return 0;
}

//시작지점을 W로 가정하고 틀린 갯수 반환
int countingW(char** board, int n, int m) {
    int wrongCount=0;

    for (int i=n; i<n+8; i++) {
        for (int j=m; j<m+8; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                if (board[i][j] == 'W') {
                    wrongCount++;
                }
            } else {
                if (board[i][j] == 'B') {
                    wrongCount++;
                }
            }
        }
    }

    return wrongCount;
}

//시작지점을 B로 가정하고 틀린 갯수 반환
int countingB(char** board, int n, int m) {
    int wrongCount=0;

    for (int i=n; i<n+8; i++) {
        for (int j=m; j<m+8; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                if (board[i][j] == 'B') {
                    wrongCount++;
                }
            } else {
                if (board[i][j] == 'W') {
                    wrongCount++;
                }
            }
        }
    }

    return wrongCount;
}