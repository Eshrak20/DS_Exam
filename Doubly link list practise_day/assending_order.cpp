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

void input_at_tail(Group *&head, Group *&tail, int value)
{
    Group *newNode = new Group(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->previous = tail;
    tail = tail->next;
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
int main()
{
    Group *head = NULL;
    Group *tail = NULL;

    int input;
    while (true)
    {
        cin >> input;
        if (input == -1)
            break;
        input_at_tail(head, tail, input);
    }
    for (Group *i = head; i->next != NULL; i = i->next)
    {
        for (Group *j = i->next; j != NULL; j = j->next)
        {
            if (i->value > j->value)
            {
                swap(i->value, j->value);
            }
        }
    }
    print_forward(head);

    return 0;
}