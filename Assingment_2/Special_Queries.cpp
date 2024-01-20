#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    queue<string> q;
    for (int i = 0; i < x; i++)
    {
        int y;
        string s;
        cin >> y;
        if (y == 0)
        {
            cin >> s;
            q.push(s);
        }
        else
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}