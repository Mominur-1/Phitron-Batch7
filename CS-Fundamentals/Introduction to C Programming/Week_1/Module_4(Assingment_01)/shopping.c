// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-c-programming-a-batch-07/challenges

#include <stdio.h>

int main()
{

    unsigned int N;
    scanf("%u", &N);

    if (N > 1000)
    {
        printf("I will buy Punjabi\n");

        N -= 1000;

        if (N >= 500)
        {
            printf("I will buy new shoes\nAlisa will buy new shoes\n");
        }
    }
    else
    {
        printf("Bad luck!\n");
    }

    return 0;
}