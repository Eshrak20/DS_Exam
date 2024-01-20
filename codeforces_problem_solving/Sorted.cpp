#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x;
    cin >> x;
    while (x--)
    {
        int flag = 1;

        long long int input;
        cin >> input;
        vector<long long int> v(input);
        for (int i = 0; i < input; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < input - 1; i++)
        {
            for (int j = i + 1; j < input; j++)
            {
                if (v[i] <= v[j])
                {
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}