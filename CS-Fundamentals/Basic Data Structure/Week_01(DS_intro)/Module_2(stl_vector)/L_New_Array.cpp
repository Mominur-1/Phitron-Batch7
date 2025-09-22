#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v;
    cin >> n;
    vector<int> A, B, C;

    for (int i = 0; i < n*2; i++)
    {
        cin >> v;
        ((i < n) ? A : B).push_back(v); 
    }

    for (int x : B)
    {
        C.push_back(x);
    }
    
    
    for (int x : A)
    {
        C.push_back(x);
    }
    
    for (int x : C)
    {
        cout << x << " ";
    }
     
    return 0;
}