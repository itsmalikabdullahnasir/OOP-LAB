#include <iostream>
#include <list>
#include <string>

class Task {
public:
    std::string name;
    bool completed;

    Task(std::string name) : name(name), completed(false) {}
};

class ToDoList {
private:
    std::list<Task> tasks;
    std::list<ToDoList> subLists;
    std::string name;

public:
    ToDoList(std::string name) : name(name) {}

    void addTask(std::string taskName) {
        tasks.push_back(Task(taskName));
    }

    void addSubList(const ToDoList& subList) {
        subLists.push_back(subList);
    }

    void display(int level = 0) const {
        for (int i = 0; i < level; ++i)
            std::cout << "  ";
        std::cout << "- " << name << ":\n";

        for (const auto& task : tasks) {
            for (int i = 0; i < level + 1; ++i)
                std::cout << "  ";
            std::cout << "- " << task.name << (task.completed ? " (Completed)" : "") << std::endl;
        }

        for (const auto& subList : subLists) {
            subList.display(level + 1);
        }
    }
};

int main() {
    ToDoList mainList("Main List");

    mainList.addTask("Task 1");
    mainList.addTask("Task 2");

    ToDoList subList1("Sub List 1");
    subList1.addTask("Task 1.1");
    subList1.addTask("Task 1.2");

    ToDoList subList2("Sub List 2");
    subList2.addTask("Task 2.1");

    mainList.addSubList(subList1);
    mainList.addSubList(subList2);

    mainList.display();

    return 0;
}
