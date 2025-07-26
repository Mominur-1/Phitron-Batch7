#include <stdio.h>
int count_before_one(int A[], int n)
{
    for (int i = 0 ; i < n; i++)
    {
        if (A[i] == 1)
        {
            return i;
        }
    }
    return n;
}
int main()
{
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }


    int elements_b_1 = count_before_one(A, N);

    printf("%d", elements_b_1);

    return 0;
}