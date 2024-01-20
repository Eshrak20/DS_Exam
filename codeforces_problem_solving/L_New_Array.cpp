#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);
    vector<int> v3(v.size()+v2.size());

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < v2.size(); i++)
    {
        cin >> v2[i];
    }

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // cout << v3.size();

    return 0;
}