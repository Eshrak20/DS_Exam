#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(const pair<string, long long int> &a, const pair<string, long long int> &b)
    {
        if (a.first < b.first)
        {
            return true;
        }
        else if (a.first > b.first)
        {
            return false;
        }
        else
        {
            if (a.second > b.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
int main()
{
    int x;
    cin >> x;
    vector<pair<string, int>> v;
    string s;
    int n;
    for (int i = 0; i < x; i++)
    {
        string s;
        long long int n;
        cin >> s;
        cin >> n;
        v.push_back({s, n});
    }
    sort(v.begin(), v.end(), cmp());
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}
