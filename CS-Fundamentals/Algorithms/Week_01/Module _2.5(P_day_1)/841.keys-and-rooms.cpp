#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int room = q.front();
            q.pop();
            for (int key : rooms[room])
            {
                if (!visited[key])
                {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }

        for (bool v : visited)
        {
            if (!v)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;

    vector<vector<int>> rooms(n);
    for (int i = 0; i < n; ++i) {
        int key;
        while (cin >> key && key != -1) {
            rooms[i].push_back(key);
        }
    }

    bool result = sol.canVisitAllRooms(rooms);
    cout << ( (result ) ? "true" : "false") << endl;
    return 0;
}
