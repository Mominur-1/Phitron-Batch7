#include <bits/stdc++.h>
using namespace std;

void counting_sort_map(string s)
{
    map<char, int> freq;
    for (char ch : s)
    {
        freq[ch]++;
    }
    
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        cout << (*it).first << " " << ":" << " " << it->second <<endl;
    }
}

void counting_sort(string s)
{
    int maxval = *max_element(s.begin(), s.end()) - 'a';
    vector<int> freq(maxval + 1);

    for (char ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            freq[ch - 'a']++;
        }
    }

    for (int i = 0; i <= maxval; i++)
    {
        if (freq[i])
        {
            cout << char('a' + i) << " " << ':' << " " << freq[i] << endl;
        }
    }
}

int main()
{
    string s;
    cin >> s;

    counting_sort(s);
   
    // counting_sort_map(s);

    return 0;
}