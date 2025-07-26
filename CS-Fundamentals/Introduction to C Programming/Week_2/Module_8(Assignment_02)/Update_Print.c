// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-c-programming-a-batch-07/challenges/update-and-print

#include <stdio.h>

int main()
{
    int N;
    short X, V;
    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%hd %hd", &X, &V);

    if (X >= 0 && X < N)
    {
        A[X] = V;
    }

    for (int i = N-1; i >= 0; i--)
    {
        printf("%d ", A[i]);
    }

    return 0;
}