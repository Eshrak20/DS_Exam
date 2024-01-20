#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        string s;
        cin >> s;
        char y;
        stack<int> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (q.empty())
            {
                q.push(s[i]);
            }
            else if (s[i] == '1')
            {
                if (q.top() == '0')
                {
                    q.pop();
                }
                else
                {
                    q.push(s[i]);
                }
            }
            else
            {
                q.push(s[i]);
            }
        }
        if (q.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}