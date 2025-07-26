#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    // for run entire loop
    for (int i = 1; i <= N; i++)
    {

        // for printing space
        for (int j = i; j < N; j++)
        {
            printf(" ");
        }

        // for printing numbers
        for (int j = i; j > 0 ; j--)
        {
            printf("%d", j);
        }
        
        printf("\n");
    }

    return 0;
}