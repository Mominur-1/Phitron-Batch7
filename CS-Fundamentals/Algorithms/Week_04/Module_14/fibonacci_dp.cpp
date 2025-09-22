#include <bits/stdc++.h>
using namespace std;
vector<long long int> dp;

// top_down
long long int fibo(long long int n)
{
    if (dp[n] == -1)
    {
        dp[n] = fibo(n - 2) + fibo(n - 1); // memoization
    }
    return dp[n];
}
int main()
{
    long long int n;
    cin >> n;
    dp.assign(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    cout << fibo(n) << " !" << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << i << ". " << dp[i] << endl;
    }

    return 0;
}