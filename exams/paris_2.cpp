#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    long long int id;
    Student(string name, long long int id)
    {
        this->name = name;
        this->id = id;
    }
};
class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.name > b.name)
        {
            return true;
        }
        else if (a.name < b.name)
        {
            return false;
        }
        else
        {
            if (a.id < b.id)
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
    long long int x;
    cin >> x;
    priority_queue<Student, vector<Student>, cmp> pq;
    for (long long int i = 0; i < x; i++)
    {
        string name;
        long long int id;
        cin >> name >> id;
        Student Eshrak_object(name, id);
        pq.push(Eshrak_object);
    }
    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().id << endl;
        pq.pop();
    }

    return 0;
}
