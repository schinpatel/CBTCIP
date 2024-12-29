#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int age;
    string address;
    string course;
    float marks;

    // Constructor to initialize student details
    Student(int r, string n, int a, string ad, string c, float m)
        : rollNo(r), name(n), age(a), address(ad), course(c), marks(m) {}

    // Display student details
    void display() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
    }
};

class StudentRecordSystem {
private:
    vector<Student> students;

public:
    // Add a new student record
    void addStudent() {
        int rollNo;
        string name, address, course;
        int age;
        float marks;

        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();  // To ignore the newline character after integer input
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();  // To ignore the newline character
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Course: ";
        getline(cin, course);
        cout << "Enter Marks: ";
        cin >> marks;

        // Create a new student and add it to the vector
        Student newStudent(rollNo, name, age, address, course, marks);
        students.push_back(newStudent);
        cout << "Student added successfully!\n";
    }

    // View all student records
    void viewStudents() {
        if (students.empty()) {
            cout << "No student records found.\n";
        } else {
            for (auto& student : students) {
                student.display();
                cout << "----------------------------\n";
            }
        }
    }

    // Modify an existing student record
    void modifyStudent() {
        int rollNo;
        cout << "Enter Roll Number of the student to modify: ";
        cin >> rollNo;

        bool found = false;
        for (auto& student : students) {
            if (student.rollNo == rollNo) {
                found = true;

                cout << "Enter new Name: ";
                cin.ignore();  // To ignore the newline character
                getline(cin, student.name);

                cout << "Enter new Age: ";
                cin >> student.age;

                cin.ignore();  // To ignore the newline character
                cout << "Enter new Address: ";
                getline(cin, student.address);

                cout << "Enter new Course: ";
                getline(cin, student.course);

                cout << "Enter new Marks: ";
                cin >> student.marks;

                cout << "Student record modified successfully!\n";
                break;
            }
        }

        if (!found) {
            cout << "Student with Roll Number " << rollNo << " not found.\n";
        }
    }

    // Delete a student record
    void deleteStudent() {
        int rollNo;
        cout << "Enter Roll Number of the student to delete: ";
        cin >> rollNo;

        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->rollNo == rollNo) {
                students.erase(it);
                cout << "Student record deleted successfully!\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with Roll Number " << rollNo << " not found.\n";
        }
    }

    // Search student by roll number
    void searchStudent() {
        int rollNo;
        cout << "Enter Roll Number of the student to search: ";
        cin >> rollNo;

        bool found = false;
        for (auto& student : students) {
            if (student.rollNo == rollNo) {
                found = true;
                student.display();
                break;
            }
        }

        if (!found) {
            cout << "Student with Roll Number " << rollNo << " not found.\n";
        }
    }
};

// Main function to display menu and interact with user
int main() {
    StudentRecordSystem system;
    int choice;

    do {
        cout << "\nStudent Record Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Modify Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Search Student by Roll Number\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.viewStudents();
                break;
            case 3:
                system.modifyStudent();
                break;
            case 4:
                system.deleteStudent();
                break;
            case 5:
                system.searchStudent();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
