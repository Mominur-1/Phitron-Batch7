// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-07/challenges/same-component
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool dfs(int si, int sj, int di, int dj)
{
    if (si == di && sj == dj)
    {
        return true;
    }

    vis[si][sj] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + mov[i].first;
        int cj = sj + mov[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            if(dfs(ci, cj, di, dj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            {
                cin >> grid[i][j];
            }
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    cout << ((dfs(si, sj, di, dj)) ? "YES" : "NO");

    return 0;
}