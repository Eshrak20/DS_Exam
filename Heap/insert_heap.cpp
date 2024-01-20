#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {50, 40, 45, 30, 35, 42, 32, 25, 20, 10};
    int x;
    cin >> x;
    v.push_back(x);
    int cur_index = v.size() - 1;
    while (cur_index != 0)
    {
        int parent_index = (cur_index - 1) / 2;
        if (v[parent_index] > v[cur_index])
        {
            swap(v[parent_index], v[cur_index]);
        }
        else
        {
            break;
        }
        cur_index = parent_index;
    }
    for (int val : v)
    {
        cout << val << " ";
    }

    return 0;
}