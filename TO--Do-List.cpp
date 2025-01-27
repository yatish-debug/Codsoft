#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task '" << task << "' added successfully." << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in your to-do list." << endl;
        } else {
            cout << "\nTo-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }

    void deleteTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task '" << tasks[index - 1] << "' deleted successfully." << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    TodoList todoList;
    int selection;

    while (true) {
        displayMenu();
        cout << "Choose an option (1-4): ";
        cin >> selection;
        cin.ignore();  

        switch (selection) {
            case 1: {
                string task;
                cout << "Enter the task you want to add: ";
                getline(cin, task);
                todoList.addTask(task);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                todoList.viewTasks();
                int taskIndex;
                cout << "Enter the number of the task to delete: ";
                cin >> taskIndex;
                todoList.deleteTask(taskIndex);
                break;
            }
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
// Coded By Yatish Hemant Bharambe // Level 1 // Task 4