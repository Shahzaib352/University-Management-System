#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <string>
using namespace std;

class Grade {
private:
//Attributes
    string Student_ID;   // ID of the student
    string Course_ID;    // ID of the course
    string GradeValue; // Letter grade or numeric grade

public:
    // Constructor
    Grade(int studentID, int courseID, const string& grade) 
        : Student_ID(studentID), Course_ID(courseID), GradeValue(grade) {}

    // Getters
    int getStudentID() const { return Student_ID; }
    int getCourseID() const { return Course_ID; }
    string getGradeValue() const { return GradeValue; }

    // Setters
    void setGradeValue(const string& grade) { GradeValue = grade; }

    // Display Grade Details
    void displayGradeDetails() const {
        cout << "Student ID: " << Student_ID << endl;
        cout << "Course ID: " << Course_ID << endl;
        cout << "Grade: " << GradeValue << endl;
    }

    string generateGrade(const int& obtainedmarks){
        switch (obtainedmarks)
        {
        case >= 90:
            return 'A+';
            break;
        case >= 85 && < 90:
            return 'A';
            break;
        case >= 80 && < 85:
            return 'A-';
            break;
        case >= 75 && < 80:
            return 'B+';
            break;
        case >= 70 && < 75:
            return 'B';
            break;
        case >= 65 && < 70:
            return 'B-';
            break;
        case >=60 && < 65:
            return 'C+';
            break;
        case >= 55 && < 60:
            return 'C';
            break;
        case >=50 && < 55:
            return 'C-';
            break;
        case < 50:
            return 'F';
            break;
        default:
            cout << "Please enter a valid input." << endl;
            break;
        }
    }

    // Overload equality operator for comparisons
    bool operator==(const Grade& other) const {
        return (Student_ID == other.Student_ID && Course_ID == other.Course_ID);
    }

    // Friend function for displaying grade via ostream
    friend ostream& operator<<(ostream& os, const Grade& grade) {
        os << "Student ID: " << grade.Student_ID << endl
           << "Course ID: " << grade.Course_ID << endl
           << "Grade: " << grade.GradeValue << endl;
        return os;
    }
};

#endif 
: