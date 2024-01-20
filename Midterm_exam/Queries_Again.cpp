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
void Insert_value_at_tail(Group *&head, Group *&tail, int value)
{

    Group *newNode = new Group(value);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
}
void Insert_value_at_head(Group *&head, Group *&tail, int value)
{

    Group *newNode = new Group(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
    return;
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
void Insert_value_at_position(Group *&head, int pos, int value)
{
    Group *temp = head;
    Group *newNode = new Group(value);
    for (int i = 1; i <= pos - 1; i++)
    {

        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->previous = newNode;
    temp->next = newNode;
    newNode->previous = temp;
}

void print_link_list(Group *head)
{

    Group *temp = head;
    cout << "L -> ";
    while (temp != NULL)
    {
        cout << temp->value
             << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_link_list_reverse(Group *tail)
{

    Group *temp = tail;
    cout << "R -> ";
    while (temp != NULL)
    {
        cout << temp->value
             << " ";
        temp = temp->previous;
    }
    cout << endl;
}
int main()
{

    int q;
    cin >> q;
    Group *head = NULL;
    Group *tail = NULL;

    for (int i = 0; i < q; i++)
    {
        int index, value;
        cin >> index;
        cin >> value;
        int x = size(head);
        if (index == x)
        {
            Insert_value_at_tail(head, tail, value);
        }
        else if (index == 0)
        {
            Insert_value_at_head(head, tail, value);
        }
        else if (index > x)
        {
            cout << "Invalid";
            cout << endl;
            continue;
        }
        else
        {
            Insert_value_at_position(head, index, value);
        }
        print_link_list(head);
        print_link_list_reverse(tail);
    };

    return 0;
}
