// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-07/challenges/area-of-component
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> vis;
vector<pair<int, int>> knightMove = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int bfs(int si, int sj, int di, int dj)
{
    int steps = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{si, sj}, steps});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (p.first == di && p.second == dj)
        {
            return steps;
        }

        for (int i = 0; i < 8; i++)
        {
            int ci = p.first + knightMove[i].first;
            int cj = p.second + knightMove[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = 1;
                q.push({{ci, cj}, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int ki, kj, qi, qj;
        cin >> n >> m;
        vis.assign(n, vector<bool>(m, false));
        cin >> ki >> kj >> qi >> qj;
        cout << bfs(ki, kj, qi, qj) << endl;
        
    }

    return 0;
}