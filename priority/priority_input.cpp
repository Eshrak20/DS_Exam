#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> p;
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            int x;
            cin >> x;
            p.push(x);
        }
        else if (n == 1)
        {
            p.pop();
        }
        else if (n == 2)
        {
            cout << p.top() << endl;
        }
        else
        {
            break;
        }
    }
    // cout << "Hello world";
    return 0;
}