#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x;
    cin >> x;
    vector<long long int> v(x);
    vector<long long int> prefix(x);

    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }
    prefix[0] = v[0];

    for (int i = 1; i < x; i++)
    {
        prefix[i] = v[i] + prefix[i - 1];
    }

    for (int i = x-1; i >= 0; i--)
    {
        cout <<  prefix[i] << " ";
    }

    return 0;
}