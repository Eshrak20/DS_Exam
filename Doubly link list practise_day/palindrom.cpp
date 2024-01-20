#include <stdio.h>
#include <iostream>
using namespace std;
int sum = 0;
int sum_2 = 0;
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
void reverse(Group *head, Group *tail, int value)
{
    Group *i = head;
    Group *j = tail;
    while (i != j && i->next != j)
    {
        swap(i->value, j->value);
        if (i->value != j->value)
        {
            flag = 0;
        }

        i = i->next;
        j = j->previous;
    }
    swap(i->value, j->value);
    if (i->value != j->value)
    {
        flag = 0;
    }
}
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
    reverse(head, tail, input);
    if (flag == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}