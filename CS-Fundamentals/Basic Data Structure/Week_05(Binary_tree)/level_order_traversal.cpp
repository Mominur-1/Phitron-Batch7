// https://www.naukri.com/code360/problems/level-order-traversal_796002?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return result;
}

BinaryTreeNode<int> *buildTreeFromInput()
{
    int val;
    if (!(cin >> val))
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(val);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front();
        q.pop();

        int l, r;
        if (!(cin >> l >> r))
            break;

        if (l != -1)
        {
            node->left = new BinaryTreeNode<int>(l);
            q.push(node->left);
        }
        if (r != -1)
        {
            node->right = new BinaryTreeNode<int>(r);
            q.push(node->right);
        }
    }

    return root;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        BinaryTreeNode<int> *root = buildTreeFromInput();
        vector<int> levelOrder = getLevelOrder(root);

        for (int val : levelOrder)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
