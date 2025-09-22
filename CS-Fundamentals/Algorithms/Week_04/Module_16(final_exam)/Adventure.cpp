// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-07/challenges/adventure-1/problem

#include <bits/stdc++.h>
using namespace std;
vector<int> W, V;
vector<vector<int>> max_total;
// int max_total_v(int i, int max_w)
// {
//     //naive aproach
//     if (i < 0 || max_w <= 0)
//     {
//         return 0;
//     }

//     if (W[i] <= max_w)
//     {
//         return max(max_total_v(i-1,max_w), max_total_v(i-1, max_w - W[i]) + V[i]);
//     }

//     return max_total_v(i-1,max_w);
// }

int max_total_v(int i, int max_w)
{
    // optimized aproach
    if (i < 0 || max_w <= 0)
    {
        return 0;
    }
    if (max_total[i][max_w] != -1)
    {
        return max_total[i][max_w];
    }
    
    int without_v = max_total_v(i - 1, max_w);

    int with_v = 0;
    if (W[i] <= max_w)
    {
        with_v = max_total_v(i - 1, max_w - W[i]) + V[i];
    }

    return max_total[i][max_w]= max(without_v, with_v);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, max_w;
        cin >> N >> max_w;
        W.resize(N);
        V.resize(N);
        max_total.assign(N, vector<int>(max_w + 1, -1));

        for (int i = 0; i < N; i++)
        {
            cin >> W[i];
        }

        for (int i = 0; i < N; i++)
        {
            cin >> V[i];
        }

        cout << max_total_v(N - 1, max_w) << endl;
    }

    return 0;
}