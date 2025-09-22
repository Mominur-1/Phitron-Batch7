#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &A, int l, int r)
{
    if (l >= r)
        return;
    A[l] = A[l] ^ A[r];
    A[r] = A[l] ^ A[r];
    A[l] = A[l] ^ A[r];

    swap (A, ++l, --r);
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    swap(A, 0, n-1);

    for (int x : A)
    {
        cout << x << " ";
    }
    

    return 0;
}