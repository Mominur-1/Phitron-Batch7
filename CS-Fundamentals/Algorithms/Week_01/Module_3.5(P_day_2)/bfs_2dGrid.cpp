#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = 1;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        cout << par.first << " " << par.second << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + mov[i].first;
            int cj = par.second + mov[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = 1;
            }
        }
    }
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

    int si, sj;
    cin >> si >> sj;

    bfs(si, sj);

    return 0;
}