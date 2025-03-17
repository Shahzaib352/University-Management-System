#ifndef Faculty_H
#define Faculty_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Faculty{
    private:
    // Attributes
    string FacultyName;
    string FacultyID;
    int FacultyCNIC;
    string status;
    string designation;
    vector<string> Subjects; // vector of strings to store multiple subjects
    vector<string> CoursesTaught; // Courses taught by the Faculty

    public:
    // Constructor
    Faculty() : FacultyName(""), FacultyID(""),FacultyCNIC(0) {}  // Default
    Faculty(string name, int id, int cnic, const vector<string>& subjects, const vector<string>& courses) {
        if(id.empty() || cnic <= 0){
            throw invalid_argument("ID must not be empty and CNIC must be positive numbers.");  // Error handling
        }
        FacultyName = name, FacultyID = id,FacultyCNIC = cnic, Subjects = subjects, CoursesTaught = courses;
    }
    Faculty(int id) : FacultyID(id) {}

    // Methids
    string getfacultyName()const{return FacultyName;}
    int getfacultyId()const{return FacultyID;}
    int getfacultyCnic()const{return FacultyCNIC;}
    const vector<string>& getSubjects() const { return Subjects; }
    const vector<string>& getCoursesTaught() const { return CoursesTaught; }

    void addSubject(const string& subject) {
        Subjects.push_back(subject);
    }

    void removeSubject(const string& subject) {
        auto it = std::find(Subjects.begin(), Subjects.end(), subject);
        if (it != Subjects.end()) {
            Subjects.erase(it);
        }
    }

    void addCourse(const string& course) {
        CoursesTaught.push_back(course);
    }

    void DisplayFacultyDetails() const{
        cout << "Faculty Name: " << FacultyName << endl;
        cout << "Faculty ID: " << FacultyID << endl;
        cout << "Faculty CNIC: " << FacultyCNIC << endl;
        cout << "Subjects: ";
        for (const string& subject : Subjects) {
            cout << subject << ", ";
        }
        cout << endl;
        cout << "Courses Taught: ";
        for (const string& course : CoursesTaught) {
            cout << course << " ";
        }
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const Faculty& faculty){
        os << "Faculty Name: " << aculty.FacultyName << endl << "Faculty ID: " << faculty.FacultyID << endl << "Faculty CNIC: " << faculty.FacultyCNIC << endl
        << "Subjects: ";
        for (const string& subject : faculty.Subjects) {
            os << subject << " ";
        }
        os << endl;
        os << "Courses Taught: ";
        for (const string& course : faculty.CoursesTaught) {
            os << course << " ";
        }
        os << endl;
        return os;
    }

    bool operator==(const Faculty& other) const{
        return FacultyID == other.FacultyID;
    }
};
#endif