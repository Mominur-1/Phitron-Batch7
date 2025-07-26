// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-for-dsa-a-batch-07/challenges/sort-it-6-3

#include <iostream>
#include <algorithm>
using namespace std;

// Custom comparison function for sorting in descending order
// bool customCompare(int a, int b) {
//     return a > b;
// }

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sorting the array in ascending order (default sorting behavior)
    sort(a, a+n);

    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    // Sorting the array in descending order using `greater<int>()`
    sort(a, a+n, greater<int>());

    // Sorting using custom comparator
    // sort(a, a+n, customCompare);
    
    // Printing the sorted array using range based loop
    for (int i : a)
    {
        cout << i << " ";
    }

    return 0;
}