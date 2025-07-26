// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-for-dsa-a-batch-07/challenges/sort-it-2-1-1

#include <iostream>
#include <algorithm>

using namespace std;

int *sort_it(int n)
{
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());

    return arr;
}

int main()
{
    int n;
    cin >> n;

    int *a = sort_it(n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    delete[] a;

    return 0;
}