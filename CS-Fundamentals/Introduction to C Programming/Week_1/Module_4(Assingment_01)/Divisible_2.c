// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-c-programming-a-batch-07/challenges

#include <stdio.h>

int main()
{

    unsigned short N;
    scanf("%hu", &N);

    for (unsigned short i = 1; i <= N; i++)
    {
        if ((i % 3) == 0 && (i % 7) == 0)
        {
            printf("%hu\n", i);
        }
    }

    return 0;
}