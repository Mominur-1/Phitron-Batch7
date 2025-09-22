#include <bits/stdc++.h>
using namespace std;

int main()
{
    list <int> mylist;

    int V;
    cin >> V;
    while (V != -1)
    {
        mylist.push_back(V);
        cin >> V;
    }

    mylist.sort();

    mylist.unique();

    for (int X : mylist)
    {
        cout << X <<" ";
    }

    return 0; 
    
}
