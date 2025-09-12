#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj_list;
vector<int> dis;

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        if (parent.second <= dis[parent.first])
        {
            for (auto child : adj_list[parent.first])
            {
                if (parent.second + child.second < dis[child.first])
                {
                    dis[child.first] = (parent.second + child.second);
                    q.push({child.first, dis[child.first]});
                }
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    adj_list.assign(n, vector<pair<int, int>>());
    dis.assign(n, INT_MAX);
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}