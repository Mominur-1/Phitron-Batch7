#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> st;

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