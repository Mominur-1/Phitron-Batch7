// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-programming-a-batch-07/challenges/count-me-2-2

#include <stdio.h>
#include <string.h>

int main()
{
    char S[100001];
    scanf("%s", &S);

    int conscnt = 0;

    for (int i = 0; i < strlen(S); i++)
    {
        if ( (S[i] != 'a') && (S[i] != 'e') && (S[i] != 'i') && (S[i] != 'o') && (S[i] != 'u') )
        {
            conscnt++;
        }

    }

    printf("%d", conscnt);
    return 0;
}