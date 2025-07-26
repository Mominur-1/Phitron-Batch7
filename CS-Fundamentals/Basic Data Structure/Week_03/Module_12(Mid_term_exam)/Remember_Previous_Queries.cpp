#include <bits/stdc++.h>
using namespace std;

void queries_perform(list<int> &list)
{
    int X, V;
    cin >> X >> V;

    if (X < 2)
    {
        (X) ? list.push_back(V) : list.push_front(V);
    }
    else if (V < list.size())
    {
        list.erase(next(list.begin(), V));
    }
}

//  Pass by const reference, no copy, no modify
void printLeftToRight(const list<int> &list)
{
    cout << "L -> ";
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// Using reverse iterators
void printRightToLeft(const list<int> &list)
{
    cout << "R -> ";
    for (auto it = list.rbegin(); it != list.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int Q;
    cin >> Q;

    list<int> mylist;
    while (Q--)
    {
        queries_perform(mylist);
        printLeftToRight(mylist);
        printRightToLeft(mylist);
    }
    
    

    return 0;
}
