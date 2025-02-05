# To-do-list

This is a simple To-Do List application built in C++ that allows users to manage their tasks efficiently. The program enables users to add, remove, view, and mark tasks as complete, ensuring an organized task management system.

The project demonstrates the use of classes, file handling, and modular programming to create a dynamic and functional application.

# How it works

toDoListMain.cpp – Handles user input and calls functions from taskManager.cpp.
taskManager.cpp – Manages task operations (add, delete, mark complete, etc.).
taskManager.h – Declares the functions used in taskManager.cpp.
fileHandler.cpp – Reads and writes tasks to tasks.txt.
fileHandler.h – Defines the functions used in fileHandler.cpp.
tasks.txt – Stores the tasks for persistence.

# How to Compile & Run

To compile this project, use a C++ compiler like g++ and enter this:
g++ -o todo toDoListMain.cpp taskManager.cpp fileHandler.cpp
./todo




