#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n < 2)
    {
        return n;
    }
    return fibo(n-2) + fibo(n-1);
}
int main()
{
    int n;
    cin >> n;

    cout << fibo(n);
    
    return 0;
}