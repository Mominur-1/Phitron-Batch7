// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-07/challenges/tetranacci-number-a-easy-version

#include <bits/stdc++.h>
using namespace std;
vector<int> fibo_sq;
//time complexity = O(n)
//bottom-up
int fibo(int n)
{
    if (fibo_sq[n] == -1)
    {
        return fibo_sq[n] = fibo(n-1) + fibo(n-2)+fibo(n-3)+fibo(n-4);
    }

    return fibo_sq[n];
}

int main()
{
    int n;
    cin >> n;
    fibo_sq.assign(n + 1, -1);//space compexity = O(n)

    for (int i = 0; i < 2; i++)
    {
        fibo_sq[i] = i;
    }

    for (int i = 1; i < 3; i++)
    {
        fibo_sq[i+1] = i;
    }

    cout << fibo(n) ;
    

    return 0;
}