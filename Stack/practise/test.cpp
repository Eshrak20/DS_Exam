#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int flag = 1;
class myStack
{
public:
    vector<int> v;
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
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
    vector<int> v;
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
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

    for (int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        st.push(y);
    }

    myStack2 st2;
    int y;
    cin >> y;

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
