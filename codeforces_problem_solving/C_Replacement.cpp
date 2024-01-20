#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    vector<int> v(x);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < v.size(); i++)
    {
       if (v[i] > 0)
       {
           v[i] = 1;
       }
       else if(v[i] < 0)
       {
           v[i] = 2;
       }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}