// https://www.hackerrank.com/contests/final-exam-a-introduction-to-c-programming-a-batch-07/challenges/difference-array

#include <stdio.h>
#include <stdlib.h>

void print_arr(short int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%hd ", arr[i]);
    }
    printf("\n");
}

void a_b_diff(short int A[], short int B[], short int C[], int n)
{
    for (int i = 0; i < n; i++)
    {
        C[i] = abs(A[i] - B[i]);
    }
}

void swap(short int arr[], int i, int min_idx)
{
    arr[i] = arr[i] + arr[min_idx];
    arr[min_idx] = arr[i] - arr[min_idx];
    arr[i] = arr[i] - arr[min_idx];

    // int temp = arr[i];
    // arr[i] = arr[min_idx];
    // arr[min_idx] = temp;
}

void selection_short(short int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(arr, i, min_idx);
        }

    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);

        short int A[N], B[N], C[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%hd", &A[j]);
            B[j] = A[j];
        }

        selection_short(B, N);

        a_b_diff(A, B, C, N);

        print_arr(C, N);
    }

    return 0;
}