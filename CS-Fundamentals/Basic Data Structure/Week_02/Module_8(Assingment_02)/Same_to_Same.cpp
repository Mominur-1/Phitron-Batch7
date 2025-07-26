#include <iostream>
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

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (!head)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

bool are_equal(Node *head1, Node *head2)
{
    while (head1 && head2)
    {
        if (head1->val != head2->val)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == NULL && head2 == NULL;
}

int main()
{
    int val, T = 2;
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;

    while (T--)
    {
        // Use references to actual list pointers
        Node *&head = (T) ? head1 : head2;
        Node *&tail = (T) ? tail1 : tail2;

        cin >> val;
        while (val != -1)
        {
            insert_at_tail(head, tail, val);
            cin >> val;
        }
    }

    cout << ((are_equal(head1, head2)) ? "YES" : "NO");

    return 0;
}
