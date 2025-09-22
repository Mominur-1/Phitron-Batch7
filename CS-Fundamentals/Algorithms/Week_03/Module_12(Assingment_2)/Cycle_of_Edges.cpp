// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-07/challenges/cycle-of-edges/problem

#include <bits/stdc++.h>
using namespace std;
// dsu(disjoint set union)
vector<int> leader;
vector<int> group_size;
int dsu_find(int node)
{
    if (leader[node] == -1)
    {
        return node;
    }

    return leader[node] = dsu_find(leader[node]);
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        leader[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        leader[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    int n, e, cycle = 0;
    cin >> n >> e;
    leader.assign(n + 1, -1);
    group_size.assign(n + 1, 1);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        if (dsu_find(a) == dsu_find(b))
        {
            cycle++;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    cout << cycle << endl;

    return 0;
}