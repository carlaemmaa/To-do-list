#include "fileHandler.h"
#include <iostream>
#include <fstream>

using namespace std;

void FileHandler::writeToFile(const vector<string>& tasks, const vector<bool>& completed) {
    ofstream file("tasks.txt");
    if (!file) {
        cerr << "Error saving tasks!" << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        file << tasks[i] << "|" << completed[i] << endl;
    }

    file.close();
}

void FileHandler::readFromFile(vector<string>& tasks, vector<bool>& completed) {
    ifstream file("tasks.txt");
    if (!file) {
        return;  // No tasks file exists yet
    }

    tasks.clear();
    completed.clear();
    string task;
    bool isCompleted;

    while (getline(file, task, '|')) {
        file >> isCompleted;
        file.ignore();
        tasks.push_back(task);
        completed.push_back(isCompleted);
    }

    file.close();
}
