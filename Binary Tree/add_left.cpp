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
int lft = 0;

Group *left()
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
void level_order(Group *root)
{
    // cout << root->value;
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
            lft = lft + keep->left->value;
            q.push(keep->left);
        }

        if (keep->right)
            q.push(keep->right);
    }
}
int main()
{
    Group *root = left();
    level_order(root);
    cout << lft;
    return 0;
}