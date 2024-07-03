#include <iostream>
#include "ArrayList.h"
#include <fstream>
#include <string>

using namespace std;

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.is_open();
}

void createFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "This file has been created because it didn't exist.\n";
        file.close();
    }
    else {
        cerr << "Error creating file!" << endl;
    }
}

void currentList(fstream& file, ArrayList& listArray) {
    string mytodo;
    int i = 1;
    file.clear(); // Clear EOF flag
    file.seekg(0); // Reset file position to the beginning for reading
    listArray.clear(); // Clear the current elements in the array
    while (getline(file, mytodo)) {
        cout << i << " " << mytodo << endl;
        listArray.addElement(mytodo);
        i++;
    }
}

void editedList(fstream& file, ArrayList& listArray) {
    file.close();
    file.open("todo.txt", ios::out | ios::trunc);
    for (int task = 0; task < listArray.size; task++) {
        string str = listArray.atIndex(task);
        file << str << endl;
    }
    file.close();
    file.open("todo.txt", ios::in | ios::out);
}

int main() {
    int option;
    string new_addition;
    ArrayList todoArrayList(0, nullptr);
    string todoFileName = "todo.txt";
    fstream todoFile;

    if (fileExists(todoFileName)) {
        cout << "File exists: \n" << todoFileName << endl;
        todoFile.open(todoFileName, ios::in | ios::out);
    }
    else {
        cout << "File does not exist. Creating file: \n" << todoFileName << endl;
        createFile(todoFileName);
        todoFile.open(todoFileName, ios::in | ios::out);
    }

    while (1) {
        currentList(todoFile, todoArrayList);
        cout << "How would you like to modify your todo (1, 2 or 0 for exit): \n";
        cout << "1. Add task: \n";
        cout << "2. Remove task: \n";
        cin >> option;

        if (option == 0) {
            break;
        }
        else if (option == 1) {
            cout << "What task would you like to add: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, new_addition);
            todoArrayList.addElement(new_addition);
            editedList(todoFile, todoArrayList);
        }
        else if (option == 2) {
            cout << "What task would you like to remove: ";
            int removeIndex;
            cin >> removeIndex;
            todoArrayList.removeElement(removeIndex - 1);
            editedList(todoFile, todoArrayList);
        }
    }

    todoFile.close();
    return 0;
}
