
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
int root;
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
        root = val;
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
int l;
int r;
void level_order(Group *root)
{
    if (root == NULL)
    {
        cout << "Tree nai" << endl;
        return;
    }
    queue<Group *> q;
    q.push(root);
    while (!q.empty())
    {
        Group *keep = q.front();
        q.pop();
        if (keep->left)
        {
            l = keep->left->value;
            q.push(keep->left);
        }

        if (keep->right)
        {
            r = keep->right->value;
            q.push(keep->right);
        }
    }
}

int main()
{
    Group *roo = input();
    level_order(roo);
    if ((l + r) == root)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}