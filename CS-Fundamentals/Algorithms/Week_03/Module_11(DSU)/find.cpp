#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> leader;

int find(int node)
{
    if (leader[node] == -1)
    {
        return node;
    }
    cout << node << " ->";
    
    return find(leader[node]);
}
int main()
{
    leader.assign(6,-1);
    leader[0] = 1;
    leader[1] = -1;
    leader[2] = 1;
    leader[3] = 1;
    leader[4] = 5;
    leader[5] = 3;

    cout << find(4) << endl;
    
    return 0;
}