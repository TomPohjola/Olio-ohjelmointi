#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;



class Student
{
public:

    Student(string, int);
    void setAge(int);
    void setName(string);
    string getName() const ;
    int getAge()const ;
    void printStudentinfo();

private:

    string name;
    int age;


};

#endif // STUDENT_H
