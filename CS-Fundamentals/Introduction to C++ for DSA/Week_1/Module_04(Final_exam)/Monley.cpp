// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-for-dsa-a-batch-07/challenges/monkey-1-2

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char a[100001];

    while (cin.getline(a, 100001))
    {
        int len = strlen(a);
        int idx = 0;

        // Copy only non-space characters into a new array
        char b[100001];
        for (int i = 0; i < len; i++)
        {
            if (a[i] != ' ')
            {
                b[idx++] = a[i];
            }
        }

        // Sort
        sort(b, b + idx);

        // Print sorted result
        for (int i = 0; i < idx; i++)
        {
            cout << b[i];
        }
        cout << endl;
    }

    return 0;
}
