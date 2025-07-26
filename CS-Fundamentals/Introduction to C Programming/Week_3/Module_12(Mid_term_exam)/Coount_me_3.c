// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-programming-a-batch-07/challenges/count-me-3

#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T)
    {
        int cap_cnt=0, sm_cnt=0, d_cnt=0 ;

        char S[10001];
        scanf("%s", &S);
        for (int i = 0; i <strlen(S); i++)
        {
            if ( S[i]>='A' && S[i]<='Z')
            {
                cap_cnt++;
            }
            else if (S[i]>='a' && S[i]<='z')
            {
                sm_cnt++;
            }
            else
            {
                d_cnt++;
            }
        }
        printf("%d %d %d\n", cap_cnt, sm_cnt, d_cnt);
        T--;
    }

    return 0;
}