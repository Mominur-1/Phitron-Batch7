// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-for-dsa-a-batch-07/challenges/choose-three

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, S;
        cin >> N >> S;

        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        bool found = 0;

        // // Brute force (O(N^3))
        // 
        // for (int i = 0; i < N - 2; i++)
        // {
        //     for (int j = i + 1; j < N - 1; j++)
        //     {
        //         for (int k = j + 1; k < N; k++)
        //         {
        //             if (A[i] + A[j] + A[k] == S)
        //             {
        //                 found = 1;
        //                 break;
        //             }
        //         }
        //         if (found)
        //         {
        //             break;
        //         }
        //     }
        //     if (found)
        //     {
        //         break;
        //     }
        // }
        //  


        // Two-Pointer Approach (O(N^2))

        sort(A, A + N);

        // Iterate over first element
        for (int i = 0; i < N - 2; i++)
        {
            int left = i + 1, right = N - 1;

            while (left < right)
            {
                int sum = A[i] + A[left] + A[right];

                if (sum == S)
                {
                    found = 1;
                    break;
                }
                else if (sum < S)
                {
                    left++; // Increase sum by select bigger element
                }
                else
                {
                    right--; // Decrease sum by select smaller element
                }
            }

            if (found)
            {
                break;
            }
        }

        cout << ((found) ? "YES" : "NO") << endl;
    }

    return 0;
}