#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        bool found = 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == x)
            {
                cout << "YES" << endl;
                found = 0;
                break;
            }
            (A[mid] < x) ? (l = mid + 1) : (r = mid - 1);
        }
        if(found) cout << "NO" << endl;
    }

    return 0;
}