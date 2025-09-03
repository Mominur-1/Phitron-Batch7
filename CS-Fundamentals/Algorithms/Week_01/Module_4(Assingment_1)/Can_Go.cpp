// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-07/challenges/can-go-1
#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool dfs(int si, int sj)
{
    vis[si][sj] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + mov[i].first;
        int cj = sj + mov[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] != '#'))
        {
            if (grid[ci][cj] == 'A' || grid[ci][cj] == 'B')
            {
                return true;
            }

            if (dfs(ci, cj))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si = -1, sj = -1;
    bool found = false;
    for (int i = 0; i < n && !found; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A' || grid[i][j] == 'B')
            {
                si = i, sj = j;
                found = true;
                break;
            }
        }
    }

    cout << (si != -1 && sj != -1 && (dfs(si, sj)) ? "YES" : "NO");

    return 0;
}