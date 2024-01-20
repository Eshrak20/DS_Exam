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
void size(Group *head, Group *head_2)
{
    Group *temp = head;
    while (temp != NULL)
    {
        sum++;
        temp = temp->next;
    }
    Group *temp_2 = head_2;
    while (temp_2 != NULL)
    {
        sum_2++;
        temp_2 = temp_2->next;
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
void input_at_tail_2(Group *&head_2, Group *&tail_2, int value)
{
    Group *newNode = new Group(value);
    if (head_2 == NULL)
    {
        head_2 = newNode;
        tail_2 = newNode;
        return;
    }
    tail_2->next = newNode;
    newNode->previous = tail_2;
    tail_2 = tail_2->next;
};
void print(Group *head, Group *head_2)
{

    if (sum == sum_2)
    {
        Group *temp = head;
        Group *temp_2 = head_2;
        while (temp != NULL)
        {
            if (temp->value == temp_2->value)
            {
                temp = temp->next;
                temp_2 = temp_2->next;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "The list is not same";
        }
        else
        {
            cout << "The list is same";
        }
    }
    else
    {
        cout << "The list size is not same";
    }
};

int main()
{
    Group *head = NULL;
    Group *tail = NULL;
    Group *head_2 = NULL;
    Group *tail_2 = NULL;
    int input;
    while (true)
    {
        cin >> input;
        if (input == -1)
            break;
        input_at_tail(head, tail, input);
    }
    while (true)
    {
        cin >> input;
        if (input == -1)
            break;
        input_at_tail_2(head_2, tail_2, input);
    }
    size(head, head_2);
    print(head, head_2);

    return 0;
}