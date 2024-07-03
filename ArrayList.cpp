#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList(int initial_size, std::string* initial_elements) {
    size = initial_size;
    elements = new std::string[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = initial_elements[i];
    }
}

ArrayList::~ArrayList() {
    delete[] elements;
}

void ArrayList::addElement(std::string new_element) {
    std::string* new_array = new std::string[size + 1];
    for (int i = 0; i < size; ++i) {
        new_array[i] = elements[i];
    }
    new_array[size] = new_element;
    delete[] elements;
    elements = new_array;
    ++size;
}

void ArrayList::removeElement(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    --size;
    std::string* new_array = new std::string[size];
    for (int i = 0; i < size; ++i) {
        new_array[i] = elements[i];
    }
    delete[] elements;
    elements = new_array;
}

void ArrayList::displayElements() {
    for (int i = 0; i < size; ++i) {
        std::cout << elements[i] << std::endl;
    }
}

std::string ArrayList::atIndex(int index) {
    if (index >= 0 && index < size) {
        return elements[index];
    }
    else {
        std::cerr << "Index out of bounds" << std::endl;
        return "";
    }
}

void ArrayList::clear() {
    delete[] elements;
    elements = new std::string[0];
    size = 0;
}
