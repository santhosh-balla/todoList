To-Do List Manager
Description:

The To-Do List Manager is a simple command-line application written in C++ that allows users to manage their to-do tasks. The program supports adding and removing tasks, and it saves the task list to a file for persistence.

Features:

Add Task: Add new tasks to your to-do list.
Remove Task: Remove tasks from your to-do list by specifying the task number.
View Current List: Display the current list of tasks.
File Persistence: Automatically saves the to-do list to a file (todo.txt) and loads it on startup.
Usage:

Add Task: Enter 1 and then type the task description.
Remove Task: Enter 2 and then type the number of the task you want to remove.
Exit: Enter 0 to exit the program.
Example:
///
File exists:
todo.txt
How would you like to modify your todo (1, 2 or 0 for exit):
1. Add task:
2. Remove task:
1
What task would you like to add: Make a sandwich
How would you like to modify your todo (1, 2 or 0 for exit):
1. Add task:
2. Remove task:
2
What task would you like to remove: 1
////
Code Structure:
main.cpp: The main application logic.
ArrayList.cpp & ArrayList.h: Implementation of the ArrayList class to manage the list of tasks.
todo.txt: The file used to store the to-do list.
Dependencies:

C++ Standard Library
