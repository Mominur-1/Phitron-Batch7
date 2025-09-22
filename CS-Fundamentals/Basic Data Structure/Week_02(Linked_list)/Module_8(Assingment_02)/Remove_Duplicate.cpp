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

// We use counting short method ( T=O(N+K), S =O(N+K)) not use selection short method ( T=O(N*N), S =O(1))
void remove_duplicates(Node *head) //But in this code (T = O(N), S = O(max(V)) );
{
    int count[1001] = {0};
    Node *curr = head;
    Node *prev = NULL;

    while (curr)
    {
        if (count[curr->val])
        {
            prev->next = curr->next; // We've seen this value before
            delete curr;
            curr = prev->next;
        }
        else
        {
            count[curr->val]++; // First time seeing this value
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    int V;
    cin >> V;
    while (V != -1)
    {
        insert_at_tail(head, tail, V);
        cin >> V;
    }

    remove_duplicates(head);

    print_linked_list(head);

    return 0;
}
