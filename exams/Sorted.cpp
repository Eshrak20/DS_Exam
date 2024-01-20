#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        set<int> s;
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int n;
            cin >> n;
            s.insert(n);
                }
        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}