// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-07/challenges/tetranacci-number

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> fibo_sq (n + 1, -1);//space compexity = O(n)

    for (int i = 0; i < 2; i++)
    {
        fibo_sq[i] = i;
    }

    for (int i = 1; i < 3; i++)
    {
        fibo_sq[i+1] = i;
    }

    // bottom-up aproach
    for (int i = 0; i <= n; i++)// t = O(n)
    {
        if (fibo_sq[i] == -1)
        {
            fibo_sq[i] = fibo_sq[i-1]+fibo_sq[i-2]+fibo_sq[i-3]+fibo_sq[i-4];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i <<". " << fibo_sq[i] << endl;
    // }
    
    cout << fibo_sq[n];

    return 0;
}