// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-07/challenges/maze-19
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<pair<int, int>>> parent; //for backtracking destination to source

vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = p.first + mov[i].first;
            int cj = p.second + mov[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                vis[ci][cj] = true;
                parent[ci][cj] = p; // store parent index in child index to backtrack
                q.push({ci, cj});
                if (grid[ci][cj] == 'D')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void markPath(int si, int sj, int di, int dj) // traverse destination to source using backtrack
{
    pair<int, int> cur = {di, dj};
    while (cur.first != si || cur.second != sj)
    {
        int px = parent[cur.first][cur.second].first;
        int py = parent[cur.first][cur.second].second;
        if (grid[px][py] == '.')
        {
            grid[px][py] = 'X';
        }
        cur = {px, py};
    }
}

int main()
{
    int si = -1, sj = -1, di = -1, dj = -1;
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i, sj = j;
            }
            else if (grid[i][j] == 'D')
            {
                di = i, dj = j;
            }
        }
    }

    if (bfs(si, sj, di, dj))
    {
        markPath(si, sj, di, dj);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}