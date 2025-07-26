// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-c-programming-a-batch-07/challenges/sum-sum-2

#include <stdio.h>

int main()
{
    int N, Sum_p = 0, Sum_n = 0;
    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (A[i] >= 0)
        {
            Sum_p += A[i];
        }
        else
        {
            Sum_n += A[i];
        }
    }
    
    printf("%d %d", Sum_p, Sum_n);
    

    return 0;
}
