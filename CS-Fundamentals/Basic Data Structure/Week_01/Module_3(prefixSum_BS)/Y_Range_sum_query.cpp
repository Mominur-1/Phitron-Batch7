#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    vector<int> A(n);
    vector<long long int> prefix_sum(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        prefix_sum[i+1] = prefix_sum[i] + A[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l-1] << endl;
    }  
    return 0;
}