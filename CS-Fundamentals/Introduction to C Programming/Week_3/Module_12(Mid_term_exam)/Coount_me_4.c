// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-programming-a-batch-07/challenges/count-me-4


#include <stdio.h>
#include <string.h>

int main()
{

    char S[10001];
    scanf("%s", &S);

    int cnt[26] = {0};

    for (int i = 0; i < strlen(S); i++)
    {
        cnt[S[i]-'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
        {
            printf("%c - %d\n", (i+'a'), cnt[i]);
        }
    }

    return 0;
}