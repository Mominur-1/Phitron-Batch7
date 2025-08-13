#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t ;

    while (t--)
    {
        int n;
        bool flag = 1;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                flag = 0;
                break;
            }
        }
        cout << ((flag) ? "YES" : "NO") << endl;
    }
    
    return 0;
}