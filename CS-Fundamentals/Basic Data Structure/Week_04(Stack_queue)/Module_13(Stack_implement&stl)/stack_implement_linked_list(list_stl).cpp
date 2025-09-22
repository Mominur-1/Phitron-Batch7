#include <bits/stdc++.h>
using namespace std;

class mystack
{
public:
    list<int> l;

    void push(int val)
    {
        l.push_back(val); // T = O(1)
    }

    void pop()
    {
        l.pop_back(); // T = O(1)
    }

    int top()
    {
        return l.back(); // T = O(1)
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
    mystack st;

    while (n--)
    {
        int a;
        cin >> a;
        st.push(a);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}