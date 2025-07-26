#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    // for run entire loop
    for (int i = 1; i < (N * 2); i++)
    {

        // for checking if line was n print .after printing line n print pattern revares
        int row = (i <= N) ? i : (N * 2 - i);

        // for print space
        for (int j = N; j > row; j--)
        {
            printf(" ");
        }

        // for print Symbols
        for (int j = 0; j < (2 * row - 1); j++)
        {
            if (row % 2 != 0)
            {
                printf("#");
            }
            else
            {
                printf("-");
            }
        }

        printf("\n");
    }

    return 0;
}

/***
// Another method
#include <stdio.h>

int main()
{
    int N, s, k = 1;
    scanf("%d", &N);
    s = N;

    // for run entire loop

    for (int i = 1; i < (2 * N); i++)
    {

        // for print space
        for (int j = 1; j < s; j++)
        {
            printf(" ");
        }

        // for Symbols
        for (int j = 1; j <= k; j++)
        {
            // for print Symbols
            if (i % 2 != 0) {
                printf("#");
            } else {
                printf("-");
            }
        }

        // for checking if line was n print .after printing line n print pattern revares
        if (i < N)
        {
            s--;
            k += 2;
        }
        else
        {
            s++;
            k -= 2;
        }

        printf("\n");
    }

    return 0;
}
 ***/