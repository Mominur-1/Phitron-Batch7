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

bool input(Node *&head, Node *&tail, int &size)
{
    int X, V;
    cin >> X;
    cin >> V;
    Node *newNode = new Node(V);
    Node *temp = NULL;
    if (X >= 0 && X <= size)
    {
        if (X == 0)
        {

            (!head) ? head = tail = newNode : (newNode->next = head, head->prev = newNode, head = newNode);
        }
        else if (X <= size)
        {
            if (X == size)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else
            {
                temp = head;
                for (int i = 1; i < X; i++)
                {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next->prev = newNode;
                newNode->prev = temp;
                temp->next = newNode;
            }
        }
        size++;
        return 1;
    }
    return 0;
}

void printRightToLeft(Node *tail)
{
    cout << "R -> ";
    for (Node *node = tail; node != NULL; node = node->prev)
    {
        cout << node->value << " ";
    }
    cout << endl;
}

void printLeftToRight(Node *head)
{
    cout << "L -> ";
    for (Node *node = head; node != NULL; node = node->next)
    {
        cout << node->value << " ";
    }
    cout << endl;
}

int main()
{
    int Q;
    cin >> Q;
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;
    while (Q--)
    {

        if (input(head, tail, size))
        {
            printLeftToRight(head);
            printRightToLeft(tail);
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}