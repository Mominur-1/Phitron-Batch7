#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void input_tree(Node *root)
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

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

void Inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    Inorder(root->left);
    cout << root->val << endl;
    Inorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    Inorder(root->left);
    Inorder(root->right);
    cout << root->val << endl;
}

void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        if (root == nullptr)
        {
            return;
        }

        Node *p = q.front();
        q.pop();

        cout << p->val << endl;
        q.push(p->left);
        q.push(p->right);
    }
}

int main()
{
    int val;
    cin >> val;
    Node *root = new Node(val);

    input_tree(root);

    cout << "Preorder traversel" << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder traversel" << endl;
    Inorder(root);
    cout << endl;

    cout << "Postorder traversel" << endl;
    postorder(root);
    cout << endl;

    cout << "levelorder traversel" << endl;
    levelorder(root);

    return 0;
}