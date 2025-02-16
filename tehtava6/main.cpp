#include "student.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int selection =0;
    vector<Student> studentList;    //luodaan vektorisäilioon oppilaat.

    studentList.push_back(Student("matti", 20));
    studentList.push_back(Student("maija", 23));
    studentList.push_back(Student("mari", 19));
    studentList.push_back(Student("markus", 22));



    do
    {


        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
        {
            string name;
            int age;
            cout << "Anna opiskelijan nimi: ";
            cin >> name;
            cout << "Anna opiskelijan ikä: ";
            cin >> age;
            studentList.push_back(Student(name, age));
            break;
        }
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            cout << "Opiskelijoiden nimet" << endl;
            for (auto &s: studentList) {
                cout << s.getName() << endl;
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });

            for (auto &s: studentList) {
                s.printStudentinfo();
            }

            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getAge() < b.getAge();
            });

            for (auto &s: studentList) {
                s.printStudentinfo();
            }

            break;
        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            string name;
            cout << "Enter student's name to find: ";
            cin >> name;
            auto it = find_if(studentList.begin(), studentList.end(), [&name](const Student& student) {
                return student.getName() == name;
            });
            if (it != studentList.end()) {
                it->printStudentinfo();
            } else {
                cout << "Opiskelijaa ei loydy" << endl;
            }
            break;
        }
        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }
    } while(selection >= 0 && selection <= 4);

    return 0;
}
