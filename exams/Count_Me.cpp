#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int i = 0; i <= x; i++)
    {
        int max = INT_MIN;

        string sentence;
        string answer;
        getline(cin, sentence);
        string word;
        stringstream ss(sentence);
        map<string, int> mp;
        while (ss >> word)
        {
            mp[word]++;
            if (max < mp[word])
            {
                max = mp[word];
                answer = word;
            }
        }
        if (max > 0)
        {
            cout << answer << " " << max << endl;
        }
    }
    return 0;
}