#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<long long int>> adj_mat;

bool floyd_warshall()
{
    for (int i = 1; i <= n; i++)
    {
        adj_mat[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (k == i) // if i == k, adj_mat[i][k] == adj_mat[i][i] && adj_mat[k][j] == adj_mat[i][j];
            {
                continue;
            }
            for (int j = 1; j <= n; j++)
            {

                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX)
                {
                    long long newDist = adj_mat[i][k] + adj_mat[k][j];
                    if (newDist < adj_mat[i][j])
                    {
                        adj_mat[i][j] = newDist;
                    }
                    if (i == j && adj_mat[i][j] < 0) // Check for negative cycle: if distance from a node to itself becomes negative
                    {
                        return true;
                    }
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
    adj_mat.assign(n + 1, vector<long long int>(n + 1, LLONG_MAX));
    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        adj_mat[a][b] = min(w, adj_mat[a][b]);
    }

    if (floyd_warshall())
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int S, T;
        cin >> S >> T;
        while (T--)
        {
            int d;
            cin >> d;
            if (adj_mat[S][d] != LLONG_MAX)
            {
                cout << adj_mat[S][d];
            }
            else
            {
                cout << "Not Possible";
            }
            cout << endl;
        }
    }

    return 0;
}