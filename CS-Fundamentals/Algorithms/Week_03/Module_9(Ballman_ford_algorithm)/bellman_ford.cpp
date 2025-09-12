#include <bits/stdc++.h>
using namespace std;
class Edge
{

public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n;
vector<int> dis;

bool bellman_ford(int src, const vector<Edge> &edge_list)
{
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++) // O(n-1) = O(n)
    {
        for (Edge ed : edge_list) // O(e)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    for (Edge ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cout << "Negative weighted cycle detected";
            return true;
        }
    }
    return false;
}

int main()
{
    int e;
    cin >> n >> e;
    vector<Edge> edge_list;
    dis.assign(n, INT_MAX);

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;
    bool flag = false;
    flag = bellman_ford(src, edge_list); // O(n*e)

    if (!flag)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " ->";
            if (dis[i] == INT_MAX)
            {
                cout << " Unreachable";
            }
            else
            {
                cout << dis[i];
            }
            cout << endl;
        }
    }

    return 0;
}