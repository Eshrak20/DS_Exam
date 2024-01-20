#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Group
{
public:
    int value;
    Group *left;
    Group *right;
    Group(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};
Group *input()
{
    int n;
    cin >> n;
    Group *root;

    if (n == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Group(n);
    }
    queue<Group *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        // 1. Bring out;
        Group *keep = q.front();
        q.pop();
        // 2.Do work;
        int l, r;
        cin >> l >> r;
        Group *myL;
        Group *myR;
        if (l == -1)
        {
            myL = NULL;
        }
        else
        {
            myL = new Group(l);
        }
        if (r == -1)
        {
            myR = NULL;
        }
        else
        {
            myR = new Group(r);
        }
        keep->left = myL;
        keep->right = myR;

        // Add children;
        if (keep->left)
            q.push(keep->left);
        if (keep->right)
            q.push(keep->right);
    }

    return root;
}

void printL(Group *root)
{
    if (root == NULL)
    {
        return;
    }
    printL(root->left);
    if (root->left == NULL)
    {
        printL(root->right);
    }
    cout << root->value << " ";

    return;
}
void print(Group *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->value << " ";
    return;
}
void printR(Group *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->value << " ";

    printR(root->right);
    if (root->right == NULL)
    {
        printR(root->left);
    }
    return;
}
int main()
{
    Group *root = input();
    printL(root->left);
    print(root);
    printR(root->right);

    return 0;
}
