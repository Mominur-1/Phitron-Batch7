#include <bits/stdc++.h>
using namespace std;

bool binary_search(const vector<int> &A, int x, int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (A[mid] == x)
        {
            return 1;
        }
        else
        {
            (A[mid] < x) ? l = (mid + 1) : r = (mid - 1);
        }
    }
    return 0;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    while (q--)
    {
        int x;
        cin >> x;

        cout << ((binary_search(A, x, n) ? "found" : "not found")) << endl;
    }

    return 0;
}