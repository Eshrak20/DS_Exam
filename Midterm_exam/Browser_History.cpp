#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
int main()
{
    while (true)
    {
        list<string> myList;
        string n;
        cin >> n;
        if (n == "end")
        {
            break;
        }
        myList.push_back(n);
    }

    int count;
    cin >> count;
    list<string> myFind;
    for (int i = 0; i < count; i++)
    {
        string x;
        cin >> x;
        myFind.push_back(x);
    }
    auto m = find(myFind.begin(), myFind.end(), "visit");
    cout << *m;
    for (auto it = myFind.begin(); it != myFind.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}

// for (auto it = myList.begin(); it != myList.end(); it++)
// {
//     cout << *it << endl;
// }