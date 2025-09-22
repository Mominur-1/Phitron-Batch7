#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> dp(n+1, -1);
    // bottom-up aproach
    for (int i = 0; i <= n; i++)
    {
        if (i < 2)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = dp[i-2] + dp[i -1];//memoization
        } 
    }

    cout << dp[n];
    
    return 0;
}