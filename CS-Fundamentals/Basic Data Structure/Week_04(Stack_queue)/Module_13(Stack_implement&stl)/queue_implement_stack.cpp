#include <bits/stdc++.h>
using namespace std;

class mystack
{
public:
    queue<int> q;
    // T = O(1)
    void push(int val)
    {
        q.push(val);
    }

    // T = O(n)
    void pop()
    {
        queue<int> q2;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            if (!q.empty())
            {
                q2.push(v);
            }
        }

        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }
    }

    // T = O(n)
    int top()
    {
        queue<int> q2;
        int v;
        while (!q.empty())
        {
            v = q.front();
            q2.push(v);
            q.pop();
        }

        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }

        return v;
    }


    // T = O(1)
    int size()
    {
        return q.size();
    }

    // T = O(1)
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    int n;
    cin >> n;
    mystack st;

    while (n--)
    {
        int a;
        cin >> a;
        st.push(a);
    }

    cout << st.size() << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    cout << st.size() << endl;

    return 0;
}