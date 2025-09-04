#include <bits/stdc++.h>
using namespace std;

int n, cycle_cnt;
bool cycle;
vector<bool> vis;
vector<bool> path_vis;
vector<vector<int>> adj_list;

void dfs(int src)
{
    vis[src] = true;
    path_vis[src] = true;

    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
        else if (path_vis[child])
        {
            cycle = true;
        }
    }
    path_vis[src] = false;
}

int main()
{
    int e;
    cin >> n >> e;
    cycle_cnt = 0;
    vis.assign(n, false);
    path_vis.assign(n, false);
    adj_list.assign(n, vector<int>());

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        cycle = 0;
        if (!vis[i])
        {
            dfs(i);
            if (cycle)
            {
                cycle_cnt++;
            }
        }
    }

    cout << cycle_cnt;

    return 0;
}