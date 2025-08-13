#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> tmp;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        tmp.push_back(A[i]);
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < N - 1; i++)
    {
        if (tmp[i] == tmp[i + 1])
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}