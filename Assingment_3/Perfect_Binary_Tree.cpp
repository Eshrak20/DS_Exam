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
int sum_tree(Group *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = sum_tree(root->left);
    int r = sum_tree(root->right);
    return (l + r + 1);
}
int max_tree(Group *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = max_tree(root->left);
    int r = max_tree(root->right);
    return (max(l, r) + 1);
}

int main()
{
    Group *root = input();
    int x = max_tree(root);
    int y = sum_tree(root);
    int m = 2;
    if (pow(m, x) - 1 == y)
    {

        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}