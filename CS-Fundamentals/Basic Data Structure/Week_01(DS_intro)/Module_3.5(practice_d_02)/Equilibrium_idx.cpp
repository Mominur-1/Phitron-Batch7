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

    int left_sum = 0, sum = 0;

    for (int i : A)
    {
        sum += i;
    }

    for (int i = 0; i < n; i++)
    {
        int right_sum = sum - left_sum - A[i];
        if (left_sum == right_sum)
        {
            cout << i << endl;
            return 0;
        }
        left_sum += A[i];
    }

    return 0;
}