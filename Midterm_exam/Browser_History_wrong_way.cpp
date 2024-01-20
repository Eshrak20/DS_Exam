#include <stdio.h>
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
    while (temp != NULL)
    {
        temp = temp->next;
    }
    tail->next = newNode;
    tail = newNode;
}
int size(Group *head)
{
    int sum = 0;
    Group *temp = head;
    while (temp != NULL)
    {
        sum++;
        temp = temp->next;
    }
    return sum;
}

void prev(Group *cur)
{
    Group *temp = cur;
    temp = temp->previous;
    cout << temp;
}
int sum = 0;
void check(Group *head, string y)
{
    Group *temp = head;
    Group *cur = head;

    if (y != "prev" && y != "next")
    {
        sum = 0;
        while (temp != NULL)
        {
            if (temp->value == y)
            {
                break;
            }
            sum++;
            temp = temp->next;
            cur = cur->next;
        }

        if (temp != NULL)
        {
            if (temp->value == y)
            {
                cout << y << endl;
            }
        }
        else
        {
            cout << "Not Available" << endl;
            sum = 0;
        }
    }

    if (y == "prev")
    {
        if (sum != 0)
        {
            sum--;
            for (int i = 0; i < sum; i++)
            {
                temp = temp->next;
            }
            if (temp != NULL)
            {

                cout << temp->value << endl;
            }
        }
        else
        {
            cout << "Not Available" << endl;
        }
    }
    if (y == "next")
    {
        if (sum < size(head) - 1)
        {
            sum++;
            for (int i = 0; i < sum; i++)
            {
                temp = temp->next;
            }
            if (temp != NULL)
            {
                cout << temp->value << endl;
            }
        }
        else
        {
            cout << "Not Available" << endl;
        }
    }
}
void visit_fun(Group *head, string visit)
{
    string y;
    if (visit == "visit")
    {
        cin >> y;
        check(head, y);
    }
    else if (visit == "prev")
    {
        string y = visit;
        check(head, y);
    }
    else if (visit == "next")
    {
        string y = visit;
        check(head, y);
    }
}
void print_list(Group *head)
{
    Group *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
int main()
{
    string input;
    Group *head = NULL;
    Group *tail = NULL;

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
    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        visit_fun(head, x);
    }
    return 0;
}