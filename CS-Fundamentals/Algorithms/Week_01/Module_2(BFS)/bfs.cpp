#include <bits/stdc++.h>
using namespace std;
bool vis[1005];

void bfs(int src, const vector<vector<int>> & adj_list )
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int child : adj_list[curr])
        {
           if (!vis[child])
           {
            q.push(child);
            vis[child] = 1;
           }
           
        }
        
    }
    
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(n, vector<int>());
    memset( vis, 0, sizeof(vis));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src;
    cin >> src;
    bfs(src, adj_list);
    
    return 0;
}