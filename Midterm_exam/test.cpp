#include <iostream>
using namespace std;
class Group
{
public:
    string value;
    Group *next;
    Group *previous;
    Group(string value)
    {
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }
};

void insert(Group *&head, Group *&tail, string value)
{
    Group *newNode = new Group(value);
    Group *temp = head;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
}

void next(Group *&cur)
{
    if (cur && cur->next)
    {
        cur = cur->next;
        cout << cur->value << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }
}

void prev(Group *&cur)
{
    if (cur && cur->previous)
    {
        cur = cur->previous;
        cout << cur->value << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }
}

void visit_fun(Group *head, Group *&cur, string y)
{
    Group *temp = head;
    while (temp)
    {
        if (temp->value == y)
        {
            cout << y << endl;
            cur = temp;
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Not Available" << endl;
    }
}

int main()
{
    string input;
    Group *head = NULL;
    Group *tail = NULL;
    Group *cur = NULL;

    while (true)
    {
        cin >> input;
        if (input == "end")
        {
            break;
        }
        insert(head, tail, input);
    }

    int n;
    cin >> n;
    string x, value;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == "visit")
        {
            cin >> value;
            visit_fun(head, cur, value);
        }
        else if (x == "next")
        {
            next(cur);
        }
        else if (x == "prev")
        {
            prev(cur);
        }
    }

    return 0;
}
