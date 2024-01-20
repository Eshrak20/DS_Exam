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
void print_leaf(Group *root, int checker)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        // cout << root->value << " ";
        if (checker == 1)
        {
            v1.push_back(root->value);
        }
        else
        {
            v2.push_back(root->value);
        }
    }
    print_leaf(root->left, checker);
    print_leaf(root->right, checker);
}
int main()
{
    Group *root_1 = input();
    Group *root_2 = input();

    print_leaf(root_1, 1);
    print_leaf(root_2, 2);

    if (v1 == v2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}