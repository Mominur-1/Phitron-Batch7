// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-07/challenges/make-it-2

// Think straightforwardly.
#include <bits/stdc++.h>
using namespace std;
//t = O(n)
bool make_it(int n) {
    while (n > 1) 
    {
        if (n % 2 == 0) 
        {
            n /= 2;
        } 
        else 
        {
            n -= 3;
        }
    }
    return n == 1;
}
// s = O(1);
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        cout << ((make_it(n)) ?"YES" : "NO")<< endl;
    }
    return 0;
}
