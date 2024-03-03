#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    Student(int id, string name, float grade) : id(id), name(name), grade(grade) {}
};

class StudentManager {
private:
    vector<Student*> records;
public:
    void addStudent(int id, string name, float grade) {
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }
    
    void updateGrade(int id, float newGrade) {
        for (Student* student : records) {
            if (student->id == id) {
                student->grade = newGrade;
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }
    
    void displayRecords() {
        for (Student* student : records) {
            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
        }
    }
    
    ~StudentManager() {
        for (Student* student : records) {
            delete student;
        }
    }
};

int main() {
    StudentManager sm;
    sm.addStudent(1, "John Doe", 92.5);
    sm.addStudent(2, "Jane Doe", 88.0);
    sm.displayRecords();
    sm.updateGrade(1, 95.0);
    sm.displayRecords();

    return 0;
}