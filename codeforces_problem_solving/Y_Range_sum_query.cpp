#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x, y;
    cin >> x >> y;
    vector<long long int> v(x);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }
    vector<long long int> prefix(x);
    prefix[0] = v[0];
    for (int i = 1; i < x; i++)
    {
        prefix[i] = v[i] + prefix[i - 1];
    }

    while (y--)
    {
        long long int m, n;
        cin >> m >> n;
        m--;
        n--;
        long long int sum;
        if (m == 0)
        {
            sum = prefix[n];
        }
        else
        {
            sum = prefix[n] - prefix[m - 1];
        }

        cout << sum << endl;
    }

    return 0;
}