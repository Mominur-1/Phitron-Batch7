#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class myqueue
{
public:
    int sz = 0;
    Node *head = NULL;
    Node *tail = NULL;

    // T = O(1)
    void push(int val)
    {
        sz++;
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
            return;
        }
        tail->next = new Node(val);
        tail = tail->next;
    }

    // T = O(1)
    void pop()
    {
        sz--;
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
        {
            tail = NULL;
        }
    }

    // T = O(1)
    int front()
    {
        return head->val;
    }
    
    // T = O(1)
    int back()
    {
        return tail->val;
    }

    // T = O(1)
    int size()
    {
        return sz;
    }

    // T = O(1)
    bool empty()
    {
        return (head == NULL);
    }
};

int main()
{
    int n;
    cin >> n;
    myqueue q;

    while (n--)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    cout << q.size() << endl;

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    cout << q.size() << endl;

    return 0;
}