// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-programming-a-batch-07/challenges/count-me-2-1

#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int devisor_2 = 0, devisor_3 = 0;
    
    for (int i = 0; i < n; i++)
    {
        if ( (A[i]%2) == 0 )
        {
            devisor_2++;
        }
        else if ( (A[i]%3) == 0 )
        {
            devisor_3 ++;
        }
    }

    printf("%d %d", devisor_2, devisor_3);
    
    return 0;
}