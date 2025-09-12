#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> leader;

int dsu_find(int node)
{
    cout << node << " ->";
    if (leader[node] == -1)
    {
        return node;
    }

    return leader[node] = dsu_find(leader[node]);
}
int main()
{
    n = 6;
    leader.assign(n, -1);
    leader[0] = 1;
    leader[1] = -1;
    leader[2] = 1;
    leader[3] = 1;
    leader[4] = 5;
    leader[5] = 3;

    cout << dsu_find(4);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i << " ->" << leader[i] << endl;
    }

    return 0;
}