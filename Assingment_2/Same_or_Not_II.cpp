#include <bits/stdc++.h>
using namespace std;
int flag = 1;
class Group
{
public:
    int value;
    Group *next;
    Group *previous;
    Group(int value)
    {
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }
};
class myStack
{
public:
    stack<int> v;
    int sz = 0;
    void push(Group *&head, Group *&tail, int val)
    {
        sz++;
        Group *newNode = new Group(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        newNode->previous = tail;
        tail->next = newNode;
        tail = tail->next;
    }
    void pop(Group *&head, Group *&tail)
    {
        sz--;
        Group *deleteNode = tail;
        tail = tail->previous;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }

        delete deleteNode;
    }
    int top(Group *&tail)
    {
        return tail->value;
    }

    bool empty()
    {
        if (sz == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class myStack2
{
public:
    int sz2 = 0;
    void push(Group *&head2, Group *&tail2, int val)
    {
        sz2++;
        Group *newNode = new Group(val);
        if (head2 == NULL)
        {
            head2 = newNode;
            tail2 = newNode;
        }
        newNode->previous = tail2;
        tail2->next = newNode;
        tail2 = tail2->next;
    }
    void pop(Group *&head2, Group *&tail2)
    {
        sz2--;
        Group *deleteNode = head2;
        head2 = head2->next;
        if (head2 == NULL)
        {
            tail2 = NULL;
        }
        else
        {
            head2->previous = NULL;
        }
        delete deleteNode;
    }
    int top(Group *&head)
    {
        return head->value;
    }
    bool empty()
    {
        if (sz2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    myStack st;
    Group *head = NULL;
    Group *tail = NULL;
    int x, y;
    cin >> x;
    cin >> y;

    for (int i = 0; i < x; i++)
    {
        int m;
        cin >> m;
        st.push(head, tail, m);
    }
    myStack2 st2;
    Group *head2 = NULL;
    Group *tail2 = NULL;
    for (int i = 0; i < y; i++)
    {
        int n;
        cin >> n;
        st2.push(head2, tail2, n);
    }
    if (st.sz == st2.sz2)
    {
        while (!st2.empty())
        {
            if (st.top(tail) != st2.top(head2))
            {

                flag = 0;
            }
            st2.pop(head2, tail2);
            st.pop(head, tail);
        }
    }
    else
    {
        flag = 0;
    }
    if (flag == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}
