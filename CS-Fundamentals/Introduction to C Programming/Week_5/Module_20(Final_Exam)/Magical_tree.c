// https://www.hackerrank.com/contests/final-exam-a-introduction-to-c-programming-a-batch-07/challenges/magical-tree-3

#include <stdio.h>

int main()
{
    short int N, X;
    scanf("%hd", &N);

    X = ((N+5)/2) + 3;

    for (int i = 1; i <= X; i++)
    {
        for (int j = 0; j < X-i; j++)
        {
            printf(" ");
        }
        
        for (int j= 0; j < (2*i)-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j < N; j++)
        {
            printf("*");
        }
        printf("\n");
    } 
    
    return 0;
}