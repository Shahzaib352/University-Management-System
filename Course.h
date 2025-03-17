#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<string>
#include"LinkedList.h"
using namespace std;

class Course{
    private:
    // Attributes
    string courseName;
    string courseCode;
    string department;
    int creditHours;

    public:
    // Constructor
    Course() : courseName(""), courseCode(""), department(""), creditHours(0) {}  // Default
    Course(string name, string code, string dept, int hours) {
        if(hours <= 0){
            throw invalid_argument("Credit Hours must be positive numbers.");  // Error handling
        }
        courseName = name, courseCode = code, department = dept, creditHours = hours;
    }
    Course(string code) : courseCode(code) {}

    // Methods
    string getcoursename()const{return courseName;}
    string getcoursecode()const{return courseCode;}
    string getdepartment()const{return department;}
    int getcredithours()const{return creditHours;}

    void displayCourseDetails()const {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Department: " << department << endl;
        cout << "Credit hours: " << creditHours << endl;
    }

    friend ostream& operator<<(ostream& os, const Course& course){
        os << "Course Name: " << course.courseName << endl << "Course Code: " << course.courseCode << endl << "Department: " << course.department << endl << "Credit hours: " << course.creditHours << endl;
        return os;
    }

    bool operator==(const Course& other)const {
        return courseCode == other.courseCode;
    }
};

#endif