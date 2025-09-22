#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string address;
    Node *next;
    Node *prev;
    Node(string address)
    {
        this->address = address;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, string address)
{
    Node *newNode = new Node(address);
    if (!head)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }
}

void visit(Node *&head)
{
    string visit_address;
    cin >> visit_address;
    bool flag = 0;
    if (visit_address == "prev" && head->prev )
    {
        head = head->prev;
        flag = 1;
    }
    else if (visit_address == "next" && head->next )
    {
        head = head->next;
        flag = 1;
    }
    else if (visit_address == "visit")
    {
        Node *left = head;
        Node *right = head;
        cin >> visit_address;

        while (left || right)
        {
            if (left && left->address == visit_address)
            {
                head = left;
                flag = 1;
                break;
            }
            if (right && right->address == visit_address)
            {
                head = right;
                flag = 1;
                break;
            }
            left = (left ? left->prev : NULL);
            right = (right ? right->next : NULL);
        }
    }
    cout << ((flag) ? head->address : "Not Available") << endl;

}

int main()
{
    int Q;
    Node *head = NULL;
    Node *tail = NULL;
    string address;
     

    cin >> Q;
    while (Q--)
    {
        visit(head);
    }
    return 0;
}