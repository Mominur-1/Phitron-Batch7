#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    vector<int> a(n);
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq.count(a[i] + 1))
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}