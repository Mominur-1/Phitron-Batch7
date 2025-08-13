#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector <int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    
    for (int i = 0; i < n; i++)
    {
        A[i] = (( A[i] == 0) ? 0 : ((A[i] > 0) ? 1 : 2 )) ;
    }
    
    for (int x : A)
    {
        cout << x << " ";
    }
    
    return 0;
}