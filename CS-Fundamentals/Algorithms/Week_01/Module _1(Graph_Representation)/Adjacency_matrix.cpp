#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj_mat(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        adj_mat[i][i] = 1;
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j])
                cout << i << " " << j << endl;
        }
    }

    return 0;
}