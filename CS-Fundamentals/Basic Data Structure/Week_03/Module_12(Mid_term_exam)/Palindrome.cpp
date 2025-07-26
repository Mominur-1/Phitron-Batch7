#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int value)
{

    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}



bool is_palindrome(Node *head, Node *tail)
{
    while (head != tail && head->prev != tail)
    {
        if (head->value != tail->value)
        {
            return false;
        }
        else
        {
            head = head->next;
            tail = tail->prev;
        }
    }
    return true;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    cin >> value;
    while (value != -1)
    {
        insert_at_tail(head, tail, value);
        cin >> value;
    }

    cout << (is_palindrome(head, tail) ? "YES" : "NO");

    return 0;
}