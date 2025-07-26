// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-c-programming-a-batch-07/challenges

#include <stdio.h>

int main() {
    
    unsigned int N;
    scanf("%u", &N);

    if ((N % 3) == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
    
    return 0;
}