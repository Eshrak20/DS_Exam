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
    // tmp->previous = NULL;
    cout << endl;
}
void delete_from_head(Group *&head)
{
    Group *deleteNode = head;
    head = head->next;
    delete deleteNode;
    head->previous = NULL;
}
void delete_from_tail(Group *&tail)
{
    Group *deleteNode = tail;
    tail = tail->previous;
    delete deleteNode;
    tail->next = NULL;
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
    // int insert_at_head;
    // cin >> insert_at_head;
    // print_forward(head);
    // print_reverse(tail);
    delete_from_head(head);
    delete_from_tail(tail);
    print_forward(head);
    print_reverse(tail);

    return 0;
}
