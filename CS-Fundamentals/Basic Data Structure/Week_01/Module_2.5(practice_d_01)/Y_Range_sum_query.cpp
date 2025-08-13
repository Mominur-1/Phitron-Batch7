#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;

    vector<int> A(n);
    vector< long long int> prefix(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        prefix[i + 1] = prefix[i]+ A[i];
    }

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        
        cout << prefix[r] - prefix[l-1] << endl;
    }
    
    return 0;
}