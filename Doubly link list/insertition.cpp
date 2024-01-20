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
void print_forward(Group *head)
{
    Group *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_reverse(Group *tail)
{
    Group *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->previous;
    }
    cout << endl;
}

void insert_at_tail(Group *&head, Group *&tail, int value)
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
    tail = tail->next;
}
void insert_at_head(Group *&head, int value)
{
    Group *newNode = new Group(value);
    head->previous = newNode;
    newNode->next = head;
    head = newNode;
    head->previous = NULL;
};
void insert_at_postion(Group *head, int value, int pos)
{
    Group *newNode = new Group(value);
    Group *tmp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    newNode->previous = tmp;
    newNode->next->previous = newNode;
};
int main()
{
    Group *head = NULL;
    Group *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_at_tail(head, tail, value);
    }
    // int insert_at_head_value;
    // cin >> insert_at_head_value;
    // int pos;
    // cin >> pos;

    // insert_at_head(head, insert_at_head_value);
    // insert_at_postion(head, insert_at_head_value, pos);
    print_forward(head);
    print_reverse(tail);
    return 0;
}
