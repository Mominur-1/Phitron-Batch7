// https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552

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

class Solution
{
    int diameter = 0;

    // Helper function to calculate height and update diameter
    int height(TreeNode<int> *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Update the diameter at this node
        diameter = max(diameter, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode<int> *root)
    {
        height(root);
        return diameter;
    }
};

void input_btree(TreeNode<int> *root)
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
    Solution solve;
    int val;
    cin >> val;
    TreeNode<int> *root = new TreeNode(val);

    input_btree(root);

    cout << solve.diameterOfBinaryTree(root);

    return 0;
}