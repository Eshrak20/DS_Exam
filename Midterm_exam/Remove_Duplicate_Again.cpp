#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> myList;
    int input;
    while (true)
    {
        cin >> input;
        if (input == -1)
        {
            break;
        }
        myList.push_back(input);
    }
    myList.sort();
    myList.unique();
    for (int val : myList)
    {
        cout << val << " ";
    }

    return 0;
}

// for (auto it = myList.begin(); it != myList.end(); it++)
// {
//     cout << *it << endl;
// }