#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> q;

    while (n--)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    cout << q.size() << endl;
    
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    cout << q.size() << endl;
    
    return 0;
}