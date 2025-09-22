#include <bits/stdc++.h>
using namespace std;

class myqueue
{
public:
    list<int> l;

    void push(int val)
    {
        l.push_back(val); // T = O(1)
    }

    void pop()
    {
        l.pop_front(); // T = O(1)
    }

    int back()
    {
        return l.back(); // T = O(1)
    }

    int front()
    {
        return l.front(); // T = O(1)
    }

    int size()
    {
        return l.size(); // T = O(1)
    }

    bool empty()
    {
        return l.empty(); // T = O(1)
    }
};

int main()
{
    int n;
    cin >> n;
    myqueue q;

    while (n--)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}