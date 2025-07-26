// https://www.hackerrank.com/contests/final-exam-a-introduction-to-c-programming-a-batch-07/challenges/matrix-38

#include <stdio.h>

int main()
{
    short int N, M;
    scanf("%hd", &N);
    scanf("%hd", &M);

    short int matrix[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%hd", &matrix[i][j]);
        }
    }

    
    for (int i = 0; i < M; i++)
    {
        printf("%hd ", matrix[N-1][i]);
    }

    printf("\n");

    for (int i = 0; i < N; i++)
    {
        printf("%hd ", matrix[i][M-1]);
    }

    
    return 0;
}