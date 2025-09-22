// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include <bits/stdc++.h>
using namespace std;

vector<int> W, V;
vector<vector<int>> max_sum;

//time complexity = O(n*max_w)
int Knapsack(int i, int max_w)
{
    if (i < 0 || max_w <= 0)
    {
        return 0;
    }

    // Check if the state has already been computed
    if (max_sum[i][max_w] != -1)
    {
        return max_sum[i][max_w];
    }

    int without_item = Knapsack(i - 1, max_w);

    int with_item = 0;
    if (W[i] <= max_w)
    {
        with_item = V[i] + Knapsack(i - 1, max_w - W[i]);
    }

    return max_sum[i][max_w] = max(without_item, with_item);
}

int main()
{
    int n, max_w;
    cin >> n >> max_w;

    W.resize(n);
    V.resize(n);
    max_sum.assign(n, vector<int>(max_w + 1, -1)); //space compexity = O(n*max_w)

    for (int i = 0; i < n; i++)
    {
        cin >> W[i] >> V[i];
    }

    cout << Knapsack(n - 1, max_w) << endl;

    return 0;
}