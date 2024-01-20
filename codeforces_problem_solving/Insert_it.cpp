#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x;
    vector<int> a(x);
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    cin >> y;
    vector<int> b(y);
    for (int i = 0; i < y; i++)
    {
        cin >> b[i];
    }
    int o;
    cin >> o;
    a.insert(a.begin()+o,b.begin(),b.end());
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}