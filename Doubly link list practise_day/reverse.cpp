#include <stdio.h>
#include <iostream>
using namespace std;
int sum = 0;
int sum_2 = 0;
int flag = 0;
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
    print_reverse(tail);

    return 0;
}