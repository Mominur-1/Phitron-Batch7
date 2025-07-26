// https://www.hackerrank.com/contests/final-exam-a-introduction-to-c-programming-a-batch-07/challenges/find-the-missing-number-11-3

#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        long long int M;
        int A, B, C;
        scanf("%lld %d %d %d", &M, &A, &B, &C);

        long long int product = (long long)A * B * C;

        if (M == 0) {
            printf("0\n");
        } else if (M % product== 0) {
            printf("%lld\n", M / product);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
