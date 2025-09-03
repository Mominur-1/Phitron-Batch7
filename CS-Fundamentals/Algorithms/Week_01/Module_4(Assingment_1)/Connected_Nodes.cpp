#include <bits/stdc++.h>
using namespace std;

void connected_nodes(int x, const vector<vector<int>> &adj_list)
{
    if (!adj_list[x].empty())
    {
        vector<int> nodes;
        for (int node : adj_list[x])
        {
            nodes.push_back(node);
        }
    
        sort(nodes.begin(), nodes.end(), greater<int>());
    
        for (int x : nodes)
        {
            cout << x << " ";
        }
    }
    else
    {
        cout << -1;
    }

    cout << endl;
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

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        connected_nodes(x, adj_list);
    }

    return 0;
}