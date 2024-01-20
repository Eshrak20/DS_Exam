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
void level_order(Group *root)
{
    // cout << root->value;
    if (root == NULL)
    {
        cout << "Tree nai" << endl;
        return;
    }
    queue<pair<Group *, int>> q;
    q.push({root, 0});
    int x, level;

    while (!q.empty())
    {
        pair<Group *, int> keep = q.front();
        Group *node = keep.first;
        level = keep.second;
        q.pop();
        cin >> x;
        if (level == x)
        {
            cout << node->value << " ";
        }
        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }
    if (x > level)
    {
        cout << "Invalid" << endl;
    }
}

int main()
{
    Group *root = input();
    level_order(root);

    return 0;
}