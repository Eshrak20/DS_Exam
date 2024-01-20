#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        if (x / 2 == i)
        {
            cout << "X" << endl;
        }
        else
        {
            cout << "\\";
            for (int n = x - (i+1); n >= 1; n--)
            {
                cout << " ";
            }
            cout << "/" << endl;
        }
    }

    return 0;
}
