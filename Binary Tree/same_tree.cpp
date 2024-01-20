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
vector<int> v1;
vector<int> v2;
vector<int> v3;
vector<int> v4;
void print_leaf_pre(Group *root, int checker)
{
    if (root == NULL)
    {
        if (checker == 1)
        {
            v1.push_back(-1);
        }
        else
        {
            v2.push_back(-1);
        }
        return;
    }
    if (checker == 1)
    {
        v1.push_back(root->value);
    }
    else
    {
        v2.push_back(root->value);
    }

    print_leaf_pre(root->left, checker);
    print_leaf_pre(root->right, checker);
}
void print_leaf_post(Group *root, int checker)
{
    if (root == NULL)
    {
        if (checker == 1)
        {
            v1.push_back(-1);
        }
        else
        {
            v2.push_back(-1);
        }
        return;
    }

    print_leaf_post(root->left, checker);
    print_leaf_post(root->right, checker);
    if (checker == 1)
    {
        v3.push_back(root->value);
    }
    else
    {
        v4.push_back(root->value);
    }
}
int main()
{
    Group *root_1 = input();
    Group *root_2 = input();
    print_leaf_pre(root_1, 1);
    print_leaf_pre(root_2, 2);
    print_leaf_post(root_1, 1);
    print_leaf_post(root_2, 2);

    if (v1 == v2 && v3 == v4)
    {

        return true;
    }
    else
    {
        return false;
    }

    return 0;
}
