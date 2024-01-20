#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    long long int id;
    long long int marks;
    Student(string name, long long int id, long long int marks)
    {
        this->name = name;
        this->id = id;
        this->marks = marks;
    }
};
class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks < b.marks)
        {
            return true;
        }
        else if (a.marks > b.marks)
        {
            return false;
        }
        else
        {
            if (a.id > b.id)
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
        long long int id, marks;
        cin >> name >> id >> marks;
        Student Eshrak_object(name, id, marks);
        pq.push(Eshrak_object);
    }
    int loop;
    cin >> loop;
    for (int i = 0; i < loop; i++)
    {
        int input;
        cin >> input;
        if (input == 1)
        {
            if (!pq.empty())
            {
                cout << pq.top().name << " " << pq.top().id << " " << pq.top().marks << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (input == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                cout << pq.top().name << " " << pq.top().id << " " << pq.top().marks << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (input == 0)
        {
            string name;
            long long int id, marks;
            cin >> name >> id >> marks;
            Student Eshrak_object(name, id, marks);
            pq.push(Eshrak_object);
            cout << pq.top().name << " " << pq.top().id << " " << pq.top().marks << endl;
        }
    }

    return 0;
}