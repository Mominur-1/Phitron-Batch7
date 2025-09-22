// https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();

            // First node at this level
            if (i == 0)
            {
                v.push_back(node->data);
            }

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
    }

    return v;
}

void input_btree(TreeNode<int> *&root)
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
            p->left = new TreeNode(l);
            q.push(p->left);
        }

        if (r != -1)
        {
            p->right = new TreeNode(r);
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
        TreeNode<int> *root = new TreeNode(val);

        input_btree(root);

        vector<int> left_view = getLeftView(root);

        for (int value : left_view )
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}