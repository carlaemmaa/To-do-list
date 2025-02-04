#include <iostream>
#include <fstream>
#include <string>
#include <vector> // Added to use the vector container
using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markTaskComplete(vector<Task> &tasks);
void deleteTask(vector<Task> &tasks);
void saveTasksToFile(const vector<Task> &tasks);
void loadTasksFromFile(vector<Task> &tasks);

int main() {
    vector<Task> tasks; // Corrected to "Task" (not "Tasks")
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markTaskComplete(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: saveTasksToFile(tasks); break;
            case 6: loadTasksFromFile(tasks); break;
            case 7: cout << "Exiting program. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    cout << "\n--- To-do List ---\n";
    cout << "1. Add a new task\n";
    cout << "2. View all tasks\n"; // Fixed description order
    cout << "3. Mark a task as complete\n";
    cout << "4. Delete a task\n";
    cout << "5. Save tasks to a file\n";
    cout << "6. Load tasks from a file\n";
    cout << "7. Exit\n";
}

void addTask(vector<Task> &tasks) {
    cin.ignore(); // Clears input buffer
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description); // Fixed "getLine" to "getline"
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }
    cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << (tasks[i].isCompleted ? " [Completed]" : " [Pending]") << endl;
    }
}

void markTaskComplete(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as complete.\n";
        return;
    }
    int index;
    cout << "Enter the task number to mark as complete: ";
    cin >> index;
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as complete.\n";
    }
}

void deleteTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }
    int index;
    cout << "Enter the task number to delete: ";
    cin >> index;
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully.\n";
    }
}

void saveTasksToFile(const vector<Task> &tasks) {
    ofstream file("tasks.txt");
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }
    for (const auto &task : tasks) {
        file << task.description << "|" << task.isCompleted << "\n";
    }
    file.close();
    cout << "Tasks saved to file.\n";
}

void loadTasksFromFile(vector<Task> &tasks) {
    ifstream file("tasks.txt");
    if (!file) {
        cout << "Error opening file for reading.\n";
        return;
    }
    tasks.clear();
    string line;
    while (getline(file, line)) {
        size_t delimiter = line.find('|');
        Task task;
        task.description = line.substr(0, delimiter);
        task.isCompleted = (line.substr(delimiter + 1) == "1");
        tasks.push_back(task);
    }
    file.close();
    cout << "Tasks loaded from file.\n";
}
