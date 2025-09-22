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

void print_linked_list(Node *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

// Insert at head; update tail if list was empty
void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (!tail)
    {
        tail = head; // Edge case: first node
    }
}

// Insert at tail; handles empty list as well
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (!head)
    {
        head = tail = newnode; // Edge case: list is empty
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

// Delete node at given index; handles head and tail updates
void delete_at_indx(Node *&head, Node *&tail, int indx)
{
    if (!head)
    {
        return; // Edge case: empty list
    }

    if (indx == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (!head)
        {
            tail = NULL; // Edge case: list becomes empty
        }
        return;
    }

    Node *temp = head;
    for (int i = 0; i < indx - 1 && temp->next; i++)
    {
        temp = temp->next;
    }

    if (!temp->next)
    {
        return; // Edge case: invalid index
    }

    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    if (deleteNode == tail)
    {
        tail = temp; // Edge case: deleting tail
    }
    delete deleteNode;
}

int main()
{
    int Q, X, V;
    Node *head = NULL, *tail = NULL;

    cin >> Q;
    while (Q--)
    {
        cin >> X >> V;
        if (X == 0)
        {
            insert_at_head(head, tail, V);
        }
        else if (X == 1)
        {
            insert_at_tail(head, tail, V);
        }
        else
        {
            delete_at_indx(head, tail, V);
        }

        print_linked_list(head);
        cout << endl;
    }

    return 0;
}