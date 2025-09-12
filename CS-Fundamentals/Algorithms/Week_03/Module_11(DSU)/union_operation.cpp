#include <bits/stdc++.h>
using namespace std;
int n;
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
    n = 6;
    leader.assign(n, -1);
    group_size.assign(n, 1);

    dsu_union(1, 2);
    dsu_union(2, 0);
    dsu_union(3, 1);
    dsu_union(3, 5);
    dsu_union(4, 5);
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " ->" << leader[i] << endl;
    }

    return 0;
}