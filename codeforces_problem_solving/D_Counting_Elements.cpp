#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int cnt = 0;
    vector<int> v(x);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < v.size(); i++)
    {
        auto it = find(v.begin(), v.end(), v[i] + 1);
        if (it != v.end())
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}