#include <bits/stdc++.h>
using namespace std;

int n, cycle_cnt;
bool cycle;
vector<bool> vis;
vector<int> p;
vector<vector<int>> adj_list;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : adj_list[curr])
        {
            if (!vis[child])
            {
                q.push(child);
                p[child] = curr;
                vis[child] = true;
            }
            else if (p[curr] != child)
            {
                cycle = true;
            }
        }
    }
}

int main()
{
    int e;
    cin >> n >> e;
    cycle_cnt = 0;
    vis.assign(n, false);
    p.assign(n, -1);
    adj_list.assign(n, vector<int>());

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        cycle = false;
        if (!vis[i])
        {
            bfs(i);
            if (cycle)
            {
                cycle_cnt++;
            }
        }
    }

    cout << cycle_cnt;

    return 0;
}