#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node **head, Node **tail, int val)
{
    Node *newnode = new Node(val);
    if (!*head)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

int find(Node *head, int X)
{
    int idx = 0;
    while (head)
    {
        if (head->val == X)
        {
            return idx;
        }
        head = head->next;
        idx++;
    }

    return -1;
}

int main()
{
    int T;

    cin >> T;

    while (T--)
    {
        Node *head = NULL;
        Node *tail = NULL;

        int V, X;
        cin >> V;
        while (V != -1)
        {
            insert_at_tail(&head, &tail, V);
            cin >> V;
        }

        cin >> X;

        cout << find(head, X) << endl;
    }

    return 0;
}
