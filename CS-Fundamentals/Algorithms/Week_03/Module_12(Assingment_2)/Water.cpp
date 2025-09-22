// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-07/challenges/water-4-1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> H(n);
        for (int i = 0; i < n; i++)
        {
            cin >> H[i];
        }

        // This initial comparison ensures the indices of the first and second largest elements are correctly initialized from the first two heights.
        //if x = y = 0 and largest_number == H[0]; this logic can not update second largest;
        int x = 0, y = 1;
        if (H[0] < H[1]) 
        {
            swap(x, y);
        }

        for (int i = 2; i < n; i++)
        {
            if (H[x] < H[i])
            {
                y = x;
                x = i;
            }
            else if (H[y] < H[i])
            {
                y = i;
            }
        }

        if (x < y)
        {
            cout << x << " " << y << endl;
        }
        else
        {
            cout << y << " " << x << endl;
        }
    }

    return 0;
}