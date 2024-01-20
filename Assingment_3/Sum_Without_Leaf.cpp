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
int print_leaf(Group *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    int l = print_leaf(root->left);
    int r = print_leaf(root->right);
    return (root->value + l + r);
}
int main()
{
    Group *root = input();
    int n = print_leaf(root);
    cout << n;
    return 0;
}