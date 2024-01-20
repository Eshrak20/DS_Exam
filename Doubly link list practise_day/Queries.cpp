#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int value)
{
    if (head == nullptr)
    {
        head = new Node(value);
        return;
    }
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node *&head, int index)
{
    if (head == nullptr)
    {
        return;
    }

    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *current = head;
    int i = 1;
    while (current->next != nullptr && i < index)
    {
        current = current->next;
        i++;
    }

    if (current->next == nullptr)
    {
        return;
    }

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
}

int main()
{
    int q;
    cin >> q;

    Node *head = nullptr;
    for (int i = 0; i < q; i++)
    {
        int x, v;
        cin >> x >> v;

        switch (x)
        {
        case 0:
            insertAtHead(head, v);
            break;
        case 1:
            insertAtTail(head, v);
            break;
        case 2:
            deleteNode(head, v);
            break;
        }

        printList(head);
    }

    return 0;
}