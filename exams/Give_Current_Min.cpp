#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int count;
    cin >> count;
    priority_queue<long long int, vector<long long int>, greater<long long int>> s;
    for (int i = 0; i < count; i++)
    {
        long long int x;
        cin >> x;
        s.push(x);
    }
    int loop;
    cin >> loop;
    for (int i = 0; i < loop; i++)
    {
        /* code */
        long long int count_2;
        cin >> count_2;
        if (count_2 == 1)
        {
            if (!s.empty())
            {
                cout << s.top() << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (count_2 == 2)
        {
            if (!s.empty())
            {
                s.pop();
            }
            if (!s.empty())
            {
                cout << s.top() << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (count_2 == 0)
        {
            long long int push;
            cin >> push;
            s.push(push);
            cout << s.top() << endl;
        }
    }

    return 0;
}