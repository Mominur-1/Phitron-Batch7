#include <bits/stdc++.h>
using namespace std;

void prefix_sum(const vector<int>& A, long long int pre, int i, int n)
{
    if (i == n)
        return;
    prefix_sum(A, pre += A[i], i+1, n);
    cout << pre << " ";
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

    prefix_sum(A, 0, 0, n);

    return 0;
}