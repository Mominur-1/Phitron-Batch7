#include <bits/stdc++.h>
using namespace std;

bool shortest_path(int src, int dest, const vector<vector<int>> &adj_list, vector<int> &vis, vector<int> &parent)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int child : adj_list[p])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                parent[child] = p;
                if (child == dest)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(n + 1, vector<int>());
    vector<int> vis(n + 1, 0), parent(n + 1, -1);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    if (shortest_path(1, n, adj_list, vis, parent))
    {

        stack<int> st;

        int curr = n;

        while (curr != -1)
        {
            st.push(curr);
            curr = parent[curr];
        }

        cout << st.size() << endl;
        
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    

    return 0;
}