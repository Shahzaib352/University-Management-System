#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<iostream>
#include<string>
#include"LinkedList.h"
#include"Student.h"
#include"Faculty.h"
#include"Course.h"
using namespace std;

class Department{
    private:
    // Attributes
    string DepartmentName;
    string DepartmentCode;
    SinglyLinkedList<Student> students;
    SinglyLinkedList<Faculty> faculties;
    SinglyLinkedList<Course> courses;

    public:
    // constructor
    Department() : DepartmentName(""), DepartmentCode("") {} // Default
    Department(const string name, const string code) : DepartmentName(name), DepartmentCode(code) {}

    // Methods
    void addStudent(const Student& student){
        students.insert(student);
        cout << "Student added successfully to " << DepartmentName << " department." << endl;
    }

    void removeStudent(string student_id) {
        students.remove(Student(student_id));
    }

    void searchStudent(string student_id){
        students.search(Student(student_id));
    }

    void updateStudent(string student_Id, const Student& updatedStudent){
        Student searchStudent(student_Id);
        students.update(searchStudent, updatedStudent);
    }

    void printStudents()const {
        cout << "Students in " << DepartmentName << " department:" << endl;
        students.display();
    }    

    void addFaculty(const Faculty& faculty){
        faculties.insert(faculty);
    }

    void removfaculty(string faculty_id){
        faculties.remove(Faculty(faculty_id));
    }

    void searchFaculty(string faculty_id){
        faculties.search(Faculty(faculty_id));
    }

    void updatfaculty(string faculty_Id, const Faculty& updatedFaculty){
        Faculty searchFaculty(faculty_Id);
        faculties.update(searchFaculty, updatedFaculty);
    }

    void printFaculty()const {
        cout << "Faculties in " << DepartmentName << " department:" << endl;
        faculties.display();
    }

    void createCourse( const Course& course){
        courses.insert(course);
        cout << "Course added successfully to " << DepartmentName << " department." << endl;
    }

    void removeCourse(string coursecode){
        courses.remove(Course(coursecode));
    }
    
    void searchCourse(string coursecode){
        courses.search(Course(coursecode));
    }

    void assignCourses(){}

    void printCourse()const {
        cout << "Courses in " << DepartmentName << " department:" << endl;
        courses.display();
    }

    void DisplayDepartmentDetails()const {
        cout << "Department Name: " << DepartmentName << endl;
        cout << "Department Code: " << DepartmentCode << endl;
        printStudents();
        printFaculty();
        printCourse();
    }

    friend ostream& operator<<(ostream os, const Department& department){
        os << "Department Name: " << department.DepartmentName << endl  << "Department Code: " << department.DepartmentCode << endl;
        department.printStudents(); 
        department.printFaculty();
        department.printCourse();
        return os;
    }

    bool operator==(const Department& other){
        return DepartmentCode == other.DepartmentCode;
    }
};

#endif