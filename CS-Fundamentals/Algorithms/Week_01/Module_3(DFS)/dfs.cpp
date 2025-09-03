#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> &vis, const vector<vector<int>> &adj_list)
{
    cout << src << " ";
    vis[src] = 1;
    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            dfs(child, vis, adj_list);
        }
        
    }
    
}

void adj_list_in(int e, vector<vector<int>> &adj_list)
{

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj_list(n, vector<int>());

    adj_list_in(e, adj_list);

    vector<int> vis(n, 0);
    int src;
    cin >> src;

    dfs(src, vis, adj_list);
    return 0;
}