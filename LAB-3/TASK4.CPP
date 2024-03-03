#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { tasks.push_back(new Task(desc)); }

    void listTasks() {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i+1 << ". " << tasks[i]->description;
            if (tasks[i]->completed) {
                cout << " (completed)";
            }
            cout << endl;
        }
    }

    void markCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber-1]->completed = true;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    ~ToDoList() { for (auto &task : tasks) delete task; }
};

int main() {
    ToDoList myList;
    myList.addTask("Finish Lab 3");
    myList.listTasks();
    myList.markCompleted(1);
    myList.listTasks();

    return 0;
}