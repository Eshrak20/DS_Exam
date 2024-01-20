#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }
    bool t = false;
    for (int i = 0; i < x; i++)
    {
        for (int j = i+1; j < x; j++)
        {
            if (v[i] == v[j])
            {
                t = true;
            }
        }
    }
    if (t == false)
    {
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}