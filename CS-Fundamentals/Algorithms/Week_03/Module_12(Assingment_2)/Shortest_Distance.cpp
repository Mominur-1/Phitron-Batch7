// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-07/challenges/shortest-distance-2

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<long long int>> adj_mat;

void floyd_warshall()
{
    for (int i = 1; i <= n; i++)
    {
        adj_mat[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        
        for (int i = 1; i <= n; i++)
        {
            if (k ==i)
            {
                continue;
            }
            for (int j = 1; j <= n; j++)
            {
                if ((adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX) && (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]))
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }
}
int main()
{
    int e;
    cin >> n >> e;
    adj_mat.assign(n + 1, vector<long long int>(n+1, LLONG_MAX));

    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        adj_mat[a][b] = min(w,adj_mat[a][b]);
    }

    floyd_warshall();

    int Q;
    cin >> Q;
    while (Q--)
    {
        int x, y;
        cin >> x >> y;
        cout << ((adj_mat[x][y] != LLONG_MAX) ? adj_mat[x][y] : -1) << endl;
    }
    

    return 0;
}