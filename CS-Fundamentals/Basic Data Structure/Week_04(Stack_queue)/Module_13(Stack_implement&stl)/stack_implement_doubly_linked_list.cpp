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
        this->prev = NULL;
    }
};

class mystack
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
        tail->next->prev = tail;
        tail = tail->next;
    }
    
    // T = O(1)
    void pop()
    {
        sz--;
        Node *temp = tail;
        tail = tail->prev;
        delete temp;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }

    // T = O(1)
    int top()
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
    mystack st;

    while (n--)
    {
        int a;
        cin >> a;
        st.push(a);
    }

    cout << st.size() << endl;
    
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << st.size() << endl;

    return 0;
}