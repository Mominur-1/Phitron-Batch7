// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-programming-a-batch-07/challenges/farmers-1

#include <stdio.h>
#include <math.h>

int main()
{
    int T, M1, M2, D;

    scanf("%d", &T);

    while (T)
    {
        scanf("%d %d %d", &M1, &M2, &D);
        printf("%d\n",(int)ceil((double)(D*M2)/(M1+M2)));
        T--;
    }

    return 0;
}