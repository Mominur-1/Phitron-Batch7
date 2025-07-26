// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-c-programming-a-batch-07/challenges/say-it

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        printf("%d. I Want More Assignments\n", i);
    }

    return 0;
}