#include <iostream>
#include "taskManager.h"

using namespace std;

int main() {
    TaskManager taskManager;
    int choice;

    do {
        cout << "\n--- To-Do List ---" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Complete" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                taskManager.addTask();
                break;
            case 2:
                taskManager.markComplete();
                break;
            case 3:
                taskManager.viewTasks();
                break;
            case 4:
                taskManager.deleteTask();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
