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
void delete_fun(Group *&head, int val)
{
    while (head->value == val)
    {
        if (head->value == val)
        {
            Group *deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
    }

    Group *tmp2 = head;

    while (tmp2->next != NULL)
    {
        if (tmp2 != NULL && tmp2->next->value == val)
        {
            Group *deleteNode = tmp2->next;
            tmp2->next = deleteNode->next;
            delete deleteNode;
        }
        else
        {
            tmp2 = tmp2->next;
        }
    }
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
int main()
{
    int input, n;
    Group *head = NULL;
    Group *tail = NULL;
    while (true)
    {
        if (input == -1)
        {
            break;
        }
        cin >> input;
        insert_at_tail(head, tail, input);
    }
    cin >> n;
    delete_fun(head, n);
    print_link_list(head);

    return 0;
}