// https://www.naukri.com/code360/problems/count-leaf-nodes_893055

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }

    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}

void input(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *p = q.front();
        q.pop();

        int l, r;
        if (!(cin >> l >> r))
        {
            break;
        }

        if (l != -1)
        {
            p->left = new BinaryTreeNode<int>(l);
            q.push(p->left);
        }

        if (r != -1)
        {
            p->right = new BinaryTreeNode<int>(r);
            q.push(p->right);
        }
    }
}
int main()
{
    /*
        Sample Tree:
              1
             / \
            2   3
           /   / \
          4   5   6

        Leaf nodes: 4, 5, 6 → Total = 3
    */
    int val;
    cin >> val;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(val);

    input(root);

    cout << noOfLeafNodes(root) << endl;

    return 0;
}