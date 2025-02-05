#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <string>

class TaskManager {
private:
    std::vector<std::string> tasks;
    std::vector<bool> completed;

public:
    TaskManager();
    void addTask();
    void markComplete();
    void viewTasks();
    void deleteTask();
    void loadTasks();
    void saveTasks();
};

#endif
