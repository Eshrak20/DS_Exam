#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
        {
            cout << char(i+97) << " "<< ":"<< " ";
            cout << cnt[i] << endl;
        }
    }
}

