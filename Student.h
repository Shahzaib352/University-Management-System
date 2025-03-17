#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
    private:
    // Attributes
    string StudentName;
    string StudentID;
    int StudentCNIC;
    string Department;
    vector<Course> courses; // List of courses
    vector<string> grades;  // List of grades

    public:
    // Constructor
    Student() : StudentName(""), StudentID(""), StudentCNIC(0), Department("") {}  // Default
    Student(string name, string id, int cnic, string department) {
        if(id.empty() || <= 0){
            throw invalid_argument("ID must not be empty and CNIC must be positive numbers.");  // Error handling
        }
        StudentName = name, StudentID = id, StudentCNIC = cnic, Department = department;
    }
    Student(string id) : StudentID(id) {}

    // Methods
    string getstudentname()const{return StudentName;}
    string getstudentid()const{return StudentID;}
    int getstudentcnic()const{return StudentCNIC;}
    string getdepartment()const{return Department;}

    void DisplayStudentDetails() const{
        cout << "Student StudentName : " << StudentName << endl;
        cout << "Student ID : " << StudentID << endl;
        cout << "Student CNIC : " << StudentCNIC << endl;
        cout << "Department : " << Department << endl;
        cout << "Courses: ";
        for (const auto& course : courses) cout << course << " ";
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const Student& student){
        os << "Student Name: " << student.StudentName << endl << "Student ID : " << student.StudentID << endl << "Student CNIC : " << student.StudentCNIC << endl << "Department : " << student.Department << endl;
        cout << "Courses: ";
        for (const auto& course : courses) {
            os << course << " ";
        }
        os << endl;
        return os;
    }

    bool operator==(const Student& other) const{
        return StudentID == other.StudentID;
    }

    void addCourse(const string& course) { courses.push_back(course); }

};

#endif