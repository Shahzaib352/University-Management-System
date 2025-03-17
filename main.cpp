#include <iostream>
#include "Student.h"
#include "Administrator.h"
#include "Authenticator.h"
#include "Department.h"
#include "Course.h"

using namespace std;

int main() {
    Authenticator authSystem; 
    Department csDepartment("Computer Science"); 
    Administrator admin("admin", "admin123"); // Administrator account
    Student student; // Student object

    int mainChoice;

    do {
        cout << "\n--- University Management System ---\n";
        cout << "1. Login as Administrator\n";
        cout << "2. Login as Student\n";
        cout << "3. Department Management\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: {
                string username, password;
                cout << "\n--- Admin Login ---\n";
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (admin.login(username, password)) {
                    int adminChoice;
                    do {
                        cout << "\n--- Admin Functionalities ---\n";
                        cout << "1. Create a New Account\n";
                        cout << "2. Delete an Account\n";
                        cout << "3. View All Accounts\n";
                        cout << "4. Search for an Account\n";
                        cout << "5. Logout\n";
                        cout << "Enter your choice: ";
                        cin >> adminChoice;

                        switch (adminChoice) {
                            case 1: {
                                string newUsername, newPassword;
                                cout << "Enter new username: ";
                                cin >> newUsername;
                                cout << "Enter new password: ";
                                cin >> newPassword;
                                admin.createAccount(authSystem, newUsername, newPassword);
                                break;
                            }
                            case 2: {
                                string usernameToDelete;
                                cout << "Enter username to delete: ";
                                cin >> usernameToDelete;
                                admin.deleteAccount(authSystem, usernameToDelete);
                                break;
                            }
                            case 3:
                                admin.viewAllAccounts(authSystem);
                                break;
                            case 4: {
                                string usernameToSearch;
                                cout << "Enter username to search: ";
                                cin >> usernameToSearch;
                                admin.searchAccount(authSystem, usernameToSearch);
                                break;
                            }
                            case 5:
                                cout << "Logging out of Admin...\n";
                                break;
                            default:
                                cout << "Invalid choice. Try again.\n";
                        }
                    } while (adminChoice != 5);
                }
                break;
            }
            case 2: {
                string username, password;
                cout << "\n--- Student Login ---\n";
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (authSystem.login(username, password)) {
                    int studentChoice;
                    do {
                        cout << "\n--- Student Functionalities ---\n";
                        cout << "1. View Courses\n";
                        cout << "2. Add a Course\n";
                        cout << "3. Drop a Course\n";
                        cout << "4. View Grades\n";
                        cout << "5. Logout\n";
                        cout << "Enter your choice: ";
                        cin >> studentChoice;

                        switch (studentChoice) {
                            case 1:
                                student.viewCourses();
                                break;
                            case 2: {
                                string courseName;
                                cout << "Enter course name to add: ";
                                cin.ignore();
                                getline(cin, courseName);
                                student.addCourse(courseName);
                                break;
                            }
                            case 3: {
                                string courseName;
                                cout << "Enter course name to drop: ";
                                cin.ignore();
                                getline(cin, courseName);
                                student.dropCourse(courseName);
                                break;
                            }
                            case 4:
                                student.viewGrades();
                                break;
                            case 5:
                                cout << "Logging out of Student...\n";
                                break;
                            default:
                                cout << "Invalid choice. Try again.\n";
                        }
                    } while (studentChoice != 5);
                }
                break;
            }
            case 3: {
                int departmentChoice;
                do {
                    cout << "\n--- Department Functionalities ---\n";
                    cout << "1. Add a Course\n";
                    cout << "2. Remove a Course\n";
                    cout << "3. Display All Courses\n";
                    cout << "4. Add a Faculty Member\n";
                    cout << "5. Remove a Faculty Member\n";
                    cout << "6. Display All Faculty Members\n";
                    cout << "7. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> departmentChoice;

                    switch (departmentChoice) {
                        case 1: {
                            string courseName, courseCode, department;
                            int creditHours;
                            cout << "Enter Course Name: ";
                            cin.ignore();
                            getline(cin, courseName);
                            cout << "Enter Course Code: ";
                            cin >> courseCode;
                            cout << "Enter Department Name: ";
                            cin.ignore();
                            getline(cin, department);
                            cout << "Enter Credit Hours: ";
                            cin >> creditHours;

                            Course newCourse(courseName, courseCode, department, creditHours);
                            csDepartment.addCourse(newCourse);
                            cout << "Course added successfully.\n";
                            break;
                        }
                        case 2: {
                            string courseCode;
                            cout << "Enter Course Code to Remove: ";
                            cin >> courseCode;

                            if (csDepartment.removeCourse(courseCode)) {
                                cout << "Course removed successfully.\n";
                            } else {
                                cout << "Course not found.\n";
                            }
                            break;
                        }
                        case 3:
                            cout << "\n--- Courses in the Department ---\n";
                            csDepartment.displayCourses();
                            break;
                        case 4: {
                            string facultyName, facultyID, department, position;
                            cout << "Enter Faculty Name: ";
                            cin.ignore();
                            getline(cin, facultyName);
                            cout << "Enter Faculty ID: ";
                            cin >> facultyID;
                            cout << "Enter Department: ";
                            cin.ignore();
                            getline(cin, department);
                            cout << "Enter Position (e.g., Professor, Lecturer): ";
                            getline(cin, position);

                            Faculty newFaculty(facultyName, facultyID, department, position);
                            csDepartment.addFaculty(newFaculty);
                            cout << "Faculty member added successfully.\n";
                            break;
                        }
                        case 5: {
                            string facultyID;
                            cout << "Enter Faculty ID to Remove: ";
                            cin >> facultyID;

                            if (csDepartment.removeFaculty(facultyID)) {
                                cout << "Faculty member removed successfully.\n";
                            } else {
                                cout << "Faculty member not found.\n";
                            }
                            break;
                        }
                        case 6:
                            cout << "\n--- Faculty Members in the Department ---\n";
                            csDepartment.displayFaculty();
                            break;
                        case 7:
                            cout << "Exiting Department Management...\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                } while (departmentChoice != 7);
                break;
            }
            case 4:
                cout << "Exiting University Management System.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (mainChoice != 4);

    return 0;
}