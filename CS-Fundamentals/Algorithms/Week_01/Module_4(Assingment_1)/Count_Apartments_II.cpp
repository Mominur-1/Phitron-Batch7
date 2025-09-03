// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-07/challenges/count-apartments-ii
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
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    bool found = 0;

    vector<int> rooms;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                if (grid[i][j] == '.')
                {
                    found = 1;
                    rooms.push_back(dfs(i, j));
                }
                else
                {
                    vis[i][j] = 1;
                }
            }
        }
    }

    if (found)
    {
        sort(rooms.begin(), rooms.end());
        for (int room : rooms)
        {
            cout << room << " ";
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}