// https://www.naukri.com/code360/problems/code-find-a-node_5682

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->val = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool find_X_recursion(const int &X, Node *&root)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->val == X)
    {
        return true;
    }
    

    return (find_X_recursion(X, root->left) || find_X_recursion(X, root->right));
}

void input_tree(Node *&root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        if (!(cin >> l >> r))
        {
            break;
        }

        if (l != -1)
        {
            p->left = new Node(l);
            q.push(p->left);
        }

        if (r != -1)
        {
            p->right = new Node(r);
            q.push(p->right);
        }
    }
}

int main()
{
    int val, X;
    cin >> val;
    Node *root = new Node(val);

    input_tree(root);

    cin >> X;

    cout << ((find_X_recursion(X, root)) ? "true" : "false");

    return 0;
}