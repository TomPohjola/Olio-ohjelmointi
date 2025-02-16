#include "student.h"



Student::Student(string n, int a)
{
    name = n;
    age = a;
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setName(string n)
{
    n = name;
}

string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

void Student::printStudentinfo()
{
    cout << "opiskelijan nimi on" << " " << name << " " << "ja ika on" << " " << age << " " << endl;
}
