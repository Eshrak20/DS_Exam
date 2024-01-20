#include <stdio.h>
#include <iostream>
using namespace std;
class Group
{
public:
    int value;
    Group *next;
    Group(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};
void insert_at_tail(Group *&head, Group *&tail, int value)
{

    Group *newNode = new Group(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}
void delete_link_list(Group *head, int x)
{
    Group *temp = head;
    while (x != 1)
    {
        x--;
        temp = temp->next;
    }
    Group *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
void delete_head(Group *head)
{
    Group *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Group *deleteNode = temp;
    temp->next = temp;
    delete deleteNode;

    // cout << temp->value;
};
void print_link_list(Group *head)
{
    Group *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
void print_link_list_2(Group *head)
{
    Group *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
int size(Group *head)
{
    Group *temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum++;
        temp = temp->next;
    }
    return sum;
}
int main()
{
    int input, n;
    Group *head = NULL;
    Group *tail = NULL;
    while (true)
    {
        cin >> input;
        if (input == -1)
            break;
        insert_at_tail(head, tail, input);
    }
    cin >> n;
    int x = size(head) - n;
    if (x != 0)
    {
        delete_link_list(head, x);
        print_link_list(head);
    }
    else
    {
        print_link_list_2(head);
    }

    return 0;
}