// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-c-programming-a-batch-07/challenges/reverse-and-odd

#include <stdio.h>

int main()
{
    int N, X;
    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    X = (N % 2 == 0)
        ? N - 1 : N - 2;
    for (int i = X; i > 0; i -= 2)
    {
        printf("%d ", A[i]);
    }

    return 0;
}