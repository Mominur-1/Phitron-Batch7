// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-07/challenges/can-go-again

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
vector<Edge> edge_list;
vector<long long int> dis;

bool bellman_ford(int src)
{
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (const Edge ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    for (const Edge ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int e;
    cin >> n >> e;
    dis.assign(n + 1, LLONG_MAX);

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }
    int S, T;
    cin >> S >> T;

    bool flag = false;
    flag = bellman_ford(S);
    if (flag)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        while (T--)
        {
            int d;
            cin >> d;
            if (dis[d] != LLONG_MAX)
            {
                cout << dis[d];
            }
            else
            {
                cout << "Not Possible";
            }
            cout << endl;
        }
    }

    return 0;
}