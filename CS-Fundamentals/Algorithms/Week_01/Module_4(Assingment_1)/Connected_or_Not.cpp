// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-07/challenges/connected-or-not-1-1
#include <bits/stdc++.h>
using namespace std;

bool connected(int a, int b, const vector<vector<int>> &adj_mat)
{
    return ((adj_mat[a][b] == 1) ? 1 : 0);
}

void adj_matrix(int n, int e, vector<vector<int>> &adj_mat)
{

    for (int i = 0; i < n; i++)
    {
        adj_mat[i][i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj_mat(n, vector<int>(n));

    adj_matrix(n, e, adj_mat);

    int x;
    cin >> x;
    while (x--)
    {
        int y, z;
        cin >> y >> z;

        cout << ((connected(y, z, adj_mat)) ? "YES" : "NO") << endl;
    }

    return 0;
}