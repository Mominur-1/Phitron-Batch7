// adjacency_matrix, adjacency_list and edge_list

#include <bits/stdc++.h>
using namespace std;

void edge_list(int n, const vector<pair<int, int>> &edges)
{
    for (auto x : edges)
    {
        cout << x.first << " " << x.second << endl;
    }
}

void adj_list(int n, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj_list(n);

    for (auto [a, b] : edges)
    {
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        for (int j : adj_list[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void adj_mat(int n, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj_mat(n, vector<int>(n, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     adj_mat[i][i] = 1;
    // }

    for (auto [a, b] : edges)
    {
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j])
                cout << i << " " << j << endl;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    cout << "adj_mat ->" << endl;
    adj_mat(n, edges);
    cout << endl;

    cout << "adj_list ->" << endl;
    adj_list(n, edges);
    cout << endl;

    cout << "edge_list ->" << endl;
    edge_list(n, edges);

    return 0;
}