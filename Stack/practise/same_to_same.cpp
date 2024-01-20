#include <stdio.h>
#include <iostream>
using namespace std;
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
    Group *head = NULL;
    Group *tail = NULL;
    int sz = 0;

    void push(int value)
    {
        sz++;
        Group *newNode = new Group(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->previous = tail;
        tail->next = newNode;
        tail = tail->next;
    }
    void pop()
    {
        sz--;
        Group *deleteNode = tail;
        tail = tail->previous;
        if (tail == NULL)
        {
            head == NULL;
        }
        else
        {
            tail->next = NULL;
        }
        delete deleteNode;
    }
    int top()
    {
        cout << tail->value;
    }
    int size()
    {
        cout << sz << endl;
    }
};
int main()
{
    myStack st;
    st.push(10);
    st.push(20);
    cout << st.top() << endl;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int val;
    //     cin >> val;
    //     st.push(val);
    // }

    // while (st.size() != 0)
    // {
    //     cout << st.top() << endl;
    //     st.pop();
    // }

    return 0;
}