// #include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
class myStack
{
public:
    list<int> l;
    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_back();
    }
    int top()
    {
        return l.back();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        if (l.size() == 0)
        {
            return true;
        }
        else
        {
            false;
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
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}