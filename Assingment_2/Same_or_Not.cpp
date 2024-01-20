
#include <bits/stdc++.h>
using namespace std;
int flag = 1;
class myStack
{
public:
    stack<int> v;
    void push(int val)
    {
        v.push(val);
    }
    void pop()
    {
        v.pop();
    }
    int top()
    {
        return v.top();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        if (v.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class myStack2
{
public:
    queue<int> v;
    void push(int val)
    {
        v.push(val);
    }
    void pop()
    {
        v.pop();
    }
    int top()
    {
        return v.front();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        if (v.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    myStack st;
    int x;
    cin >> x;
    int y;
    cin >> y;

    for (int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        st.push(y);
    }

    myStack2 st2;

    for (int i = 0; i < y; i++)
    {
        int y;
        cin >> y;
        st2.push(y);
    }

    if (st.size() == st2.size())
    {
        while (!st2.empty())
        {
            if (st.top() != st2.top())
            {

                flag = 0;
            }

            st2.pop();
            st.pop();
        }
    }
    else
    {
        flag = 0;
    }

    if (flag == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}
