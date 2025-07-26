#include<stdio.h>
#include <string.h>


int is_palindrome(char s[])
{
    for (int i = 0; i < strlen(s) / 2; i++)
    {
        if (s[i] != s[strlen(s)- 1 - i])
            return 0;
    }
    return 1;
}


int main()
{
    char S[10001];
    scanf("%s", S);

    if (is_palindrome(S))
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }


    return 0;
}