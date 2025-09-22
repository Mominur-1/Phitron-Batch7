#include <bits/stdc++.h>
using namespace std;

class myqueue
{
public:
    stack<int> st;
    // T = O(1)
    void push(int val)
    {
        st.push(val);
    }

    // T = O(n)
    void pop()
    {
        stack<int> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }

        st2.pop();

        while (!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }
    }

    // T = O(n)
    int front()
    {
        stack<int> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }

        int v = st2.top();

        while (!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }

        return v;
    }

    // T = O(1)
    int back()
    {
        return st.top();
    }

    // T = O(1)
    int size()
    {
        return st.size();
    }

    // T = O(1)
    bool empty()
    {
        return st.empty();
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

    cout << q.size() << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    cout << q.size() << endl;

    return 0;
}