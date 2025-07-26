// https://www.hackerrank.com/contests/final-exam-a-introduction-to-c-programming-a-batch-07/challenges/jadu-matrix

#include <stdio.h>
#include <stdbool.h>

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

    bool flag = 0;

    if (N == M)
    {
        flag = 1;
        for (int i = 0; i < N && flag; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if ((i==j) || ((i+j) == (N-1)))
                {
                    if (matrix[i][j] != 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                else
                {
                    if (matrix[i][j] != 0)
                    {
                        flag = 0;
                        break;
                    }
                } 
            }
        }
    }

    printf((flag)? ("YES") : ("NO"));

    return 0;
}


/***
 
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    if (N != M) {
        printf("NO\n");
        return 0;
    }

    bool isJadu = 1;
    for (int i = 0; i < N && isJadu; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int val;
            scanf("%d", &val);

            bool onDiagonal = (i == j) || (i + j == N - 1);
            if ((onDiagonal && val != 1) || (!onDiagonal && val != 0)) {
                isJadu = 0;
                break;
            }
        }
    }

    printf(isJadu ? "YES\n" : "NO\n");
    return 0;
}
    ***/
