#include <bits/stdc++.h>
using namespace std;
string S1, S2;
bool pile_of_world_map()
{
    map <char, int> freq;
    
    for (char c : S1)
    {
        freq[c]++;
    }
    
    for (char c : S2)
    {
        freq[c]--;
    }
    
    for (pair p : freq)
    {
        if (p.second)
        {
            return false;
        }
    }
    
    return true;
}
bool Pile_of_world_freq()
{
    vector<int> freq(58, 0);

    for (int i = 0; i < S1.size(); i++)
    {
        freq[S1[i] - 'A']++;
        freq[S2[i] - 'A']--;
    }

    bool Pile_of_world = true;

    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i])
        {
            return false;
        }
    }

    return true;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> S1 >> S2;

        if (S1.size() != S2.size())
        {
            cout << "NO" << endl;
            continue;
        }

        // if (Pile_of_world_freq())
        // {
        //     cout << "YES" ;
        // }
        // else
        // {
        //     cout << "NO" ;
        // }
        // cout << endl;

        if (pile_of_world_map())
        {
            cout << "YES" ;
        }
        else
        {
            cout << "NO" ;
        }
        cout << endl;
    }
    return 0;
}