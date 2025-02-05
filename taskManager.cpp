#include "taskManager.h"
#include "fileHandler.h"
#include <iostream>

using namespace std;

TaskManager::TaskManager() {
    loadTasks();  // Load saved tasks at startup
}

void TaskManager::addTask() {
    string task;
    cout << "Enter task description: ";
    cin.ignore();  
    getline(cin, task);
    tasks.push_back(task);
    completed.push_back(false);
    saveTasks();
    cout << "Task added successfully!" << endl;
}

void TaskManager::markComplete() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    int index;
    cout << "Enter task number to mark as complete: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        completed[index - 1] = true;
        saveTasks();
        cout << "Task marked as complete!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void TaskManager::viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "\n--- To-Do List ---" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". [" << (completed[i] ? "✓" : " ") << "] " << tasks[i] << endl;
    }
}

void TaskManager::deleteTask() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + (index - 1));
        completed.erase(completed.begin() + (index - 1));
        saveTasks();
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void TaskManager::loadTasks() {
    FileHandler fileHandler;
    fileHandler.readFromFile(tasks, completed);
}

void TaskManager::saveTasks() {
    FileHandler fileHandler;
    fileHandler.writeToFile(tasks, completed);
}
