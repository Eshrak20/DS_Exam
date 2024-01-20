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
        queue<int> q;
        queue<int> qq;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                q.push(s[i]);
            }
            else
            {
                qq.push(s[i]);
            }
        }
        if (q.size() == qq.size())
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