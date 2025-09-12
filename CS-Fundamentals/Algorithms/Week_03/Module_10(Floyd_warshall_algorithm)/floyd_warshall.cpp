#include <bits/stdc++.h>
using namespace std;
int n;

bool floyd_warshall(vector<vector<int>> &adj_mat)
{
    // int (*adj_mat)[n] = (int (*)[n])arr;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == k)
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (!(adj_mat[i][k] == INT_MAX || adj_mat[k][j] == INT_MAX) && (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]))
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
                if (i == j && adj_mat[i][j] < 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int e;
    cin >> n >> e;
    vector<vector<int>> adj_mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj_mat[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(c,adj_mat[a][b]);
    }

    if (floyd_warshall(adj_mat))
    {
        cout << "Negative weighted cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][j] != INT_MAX)
                {
                    cout << adj_mat[i][j] << " ";
                }
                else
                {
                    cout << "INF";
                }
            }
            cout << endl;
        }
    }
    return 0;
}