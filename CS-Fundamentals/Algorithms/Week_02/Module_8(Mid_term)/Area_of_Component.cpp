// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-07/challenges/area-of-component
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

int dfs(int si, int sj)
{
    int cnt = 1;
    vis[si][sj] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + mov[i].first;
        int cj = sj + mov[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            vis[ci][cj] = 1;
            cnt += dfs(ci, cj);
        }
    }
    return cnt;
}

int main()
{
    int min_area = INT_MAX;
    cin >> n >> m;
    grid.assign(n, vector<char>(m, 0));
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<int> rooms;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                if (grid[i][j] == '.')
                {
                    int x = dfs(i, j);
                    if (min_area > x)
                    {
                        min_area = x;
                    }
                }
                else
                {
                    vis[i][j] = 1;
                }
            }
        }
    }

    if (min_area != INT_MAX)
    {
        cout << min_area;
    }
    else
    {
        cout << -1;
    }

    return 0;
}