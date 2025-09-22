// https://www.naukri.com/code360/problems/node-level_920383

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    bool isOriginal;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int nodeLevel(TreeNode<int> *root, int searchedValue)
{
    int level = 1;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            TreeNode<int> *p = q.front();
            q.pop();

            if (p->val == searchedValue)
            {
                return level;
            }

            if (p->left)
            {
                q.push(p->left);
            }

            if (p->right)
            {
                q.push(p->right);
            }
        }
        level++;
    }
    return 0;
}

void input(TreeNode<int> *&root)
{
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *p = q.front();
        q.pop();

        int l, r;
        if (!(cin >> l >> r))
        {
            break;
        }

        if (l != -1)
        {
            p->left = new TreeNode<int>(l);
            q.push(p->left);
        }

        if (r != -1)
        {
            p->right = new TreeNode<int>(r);
            q.push(p->right);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int val;
        cin >> val;
        TreeNode<int> *root = new TreeNode<int>(val);

        input(root);

        int x;
        cin >> x;

        cout << ((root == nullptr) ? -1 : nodeLevel(root, x)) << endl;
    }

    return 0;
}