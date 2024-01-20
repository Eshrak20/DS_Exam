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
int m;
Group *input()
{
    int val;
    cin >> val;
    Group *main;
    if (val == -1)
    {
        main = NULL;
    }
    else
    {
        main = new Group(val);
        m = val;
    }
    queue<Group *> q;
    if (main)
    {
        q.push(main);
    }
    while (!q.empty())
    {
        // 1. Bring out;
        Group *keep = q.front();
        q.pop();
        // 2.Do work;
        int l, r;
        cin >> l >> r;
        Group *myLeft;
        Group *myRight;
        if (l == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Group(l);
        }
        if (r == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Group(r);
        }
        keep->left = myLeft;
        keep->right = myRight;
        // connect children:
        if (keep->left)
            q.push(keep->left);
        if (keep->right)
            q.push(keep->right);
    }
    return main;
}
int flag = 1;
void level_order(Group *root)
{
    if (root == NULL)
    {
        // cout << "Tree nai" << endl;
        return;
    }
    queue<Group *> q;
    q.push(root);
    while (!q.empty())
    {
        Group *keep = q.front();
        q.pop();

        level_order(keep->left);
        if (keep->left == NULL)
        {
            return;
        }
        if (keep->left->value != m)
        {
            flag = 0;
        }
        level_order(keep->right);
        if (keep->right == NULL)
        {
            return;
        }
        if (keep->right->value != m)
        {
            flag = 0;
        }

        if (keep->left)
        {
            q.push(keep->left);
        }
        if (keep->right)
        {
            q.push(keep->right);
        }
    }
}
int main()
{
    Group *root = input();
    level_order(root);
    if (flag == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}