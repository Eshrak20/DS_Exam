#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> myList;
    int n;
    int input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input == 0)
        {
            cin >> input;
            myList.push_front(input);
        }
        else if (input == 1)
        {
            cin >> input;
            myList.push_back(input);
        }
        else if (input == 2)
        {
            cin >> input;
            if (myList.size() > input)
            {
                myList.erase(next(myList.begin(), input));
            }
        }
        cout << "L -> ";
        for (int val : myList)
        {
            cout << val << " ";
        }
        cout << endl;

        cout << "R -> ";
        myList.reverse();
        for (int val : myList)
        {
            cout << val << " ";
        }
        cout << endl;
        myList.reverse();
    }
    return 0;
}

// for (auto it = myList.begin(); it != myList.end(); it++)
// {
//     cout << *it << endl;
// }