#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <string>

class ArrayList {
public:
    ArrayList(int initial_size, std::string* initial_elements);
    ~ArrayList();
    void addElement(std::string new_element);
    void removeElement(int index);
    void displayElements();
    std::string atIndex(int index);
    void clear();
    int size;
private:
    std::string* elements;
};

#endif // ARRAYLIST_H
