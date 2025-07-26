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

int findDifference(Node *head)
{
    int maxVal = head->val;
    int minVal = head->val;
    Node *temp = head;

    while (temp)
    {
        maxVal = max(maxVal, temp->val); // int max(int a, int b) {return (a > b) ? a : b;}
        minVal = min(minVal, temp->val); // int min(int a, int b) {return (a < b) ? a : b;}

        temp = temp->next;
    }

    return maxVal - minVal;
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    cin >> val;
    while (val != -1)
    {
        insert_at_tail(head, tail, val);
        cin >> val;
    }

    cout << findDifference(head) << endl;

    return 0;
}

