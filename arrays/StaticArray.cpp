#include "StaticArray.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>

// Constructor
StaticArray::StaticArray() : data(NULL), size(0), capacity(0) {}

StaticArray::StaticArray(int initialCapacity) : data(NULL), size(0), capacity(0) {
    if (initialCapacity > 0 && initialCapacity <= MAX_SIZE) {
        data = new int[initialCapacity];
        capacity = initialCapacity;
    }
}
StaticArray::~StaticArray() {
    delete[] data;
}

void StaticArray::insertAtBeginning(int value) {
    //2 size tests
    if (size >= capacity) {
        std::cout << "Error: Array is full! Cannot insert at beginning.\n";
        return;
    }
    if (data == NULL) {
        std::cout << "Error: Array not initialized! Please create array first.\n";
        return;
    }
    for (int i = size; i > 0; i--) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    size++;
    std::cout << "Value " << value << " inserted at beginning successfully!\n";
}
void StaticArray::insertAtEnd(int value) {
    if (size >= capacity) {
        std::cout << "Error: Array is full!\n";
        return;
    }
    if (data == NULL) {
        std::cout << "Error: Array not initialized! Please create array first.\n";
        return;
    }
    data[size]=value;
    size++;
    std::cout << "Value " << value << " inserted at ending successfully!\n";
}
void StaticArray::insertAtPosition(int value, int position) {
    if (size >= capacity) {
        std::cout << "Error: Array is full!\n";
        return;
    }
    if (data == NULL) {
        std::cout << "Error: Array not initialized! Please create array first.\n";
        return;
    }
    if (position<0 || position>size) {
        std::cout <<"Position is out of range...\n";
        return;
    }
    for (int i = size; i > position; i--) {
        data[i] = data[i - 1];
    }
    data[position] = value;
    size++;
    std::cout << "Value " << value << " inserted at position " << position << " successfully!\n";
}
void StaticArray::deleteAtBeginning() {
    if (size<=0){
        std::cout<< "Array is empty...\n";
        return;
    }
    for(int i=0;i<size-1;i++){
        data[i]=data[i+1];
    }
    size--;
    data[size]=NULL;
    std::cout<< "Value deleted at beginning successfully!\n";
}

void StaticArray::deleteAtEnd() {
    if (size<=0){
        std::cout<< "Array is empty...\n";
        return;
    }
    size--;
}

void StaticArray::deleteAtPosition(int position) {
    if (size<=0){
        std::cout<< "Array is empty...\n";
        return;
    }
    if (position<0 || position>=size) {
        std::cout <<"Position is out of range...\n";
        return;
    }
    for(int i=position; i<size-1; i++){
        data[i]=data[i+1];
    }
    size--;
}

void StaticArray::createArray(int size) {
    if (size <= 0 || size > MAX_SIZE) {
        std::cout << "Error: Invalid size! Size must be between 1 and " << MAX_SIZE << std::endl;
        return;
    }
    if (data != NULL) {
        delete[] data;
    }
    data = new int[size];
    if (data == NULL) {
        std::cout << "Error: Memory allocation failed!" << std::endl;
        return;
    }
    this->size = 0;
    this->capacity = size;
    
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
    std::cout << "Array created successfully with capacity " << size << std::endl;
}

void StaticArray::display() const {
    if (data == NULL) {
        std::cout << "Error: Array not initialized! Please create array first." << std::endl;
        return;
    }
    if (size == 0) {
        std::cout << "Array is empty." << std::endl;
        return;
    }
    std::cout << "Array elements: [";
    for (int i = 0; i < size; i++) {
        std::cout << data[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << "Size: " << size << ", Capacity: " << capacity << std::endl;
}

bool StaticArray::search(int value) const {
    for(int i=0;i<size;i++){
        if(data[i]==value){
            return true;
        }
    }
    return false;
}

void StaticArray::updateAtPosition(int position, int newValue) {
    if(position<0 || position>=size){
        std::cout<<"Position is out of range...\n";
        return;
    }
    data[position]=newValue;
}

void StaticArray::updateValue(int oldValue, int newValue) {
    bool found = false;
    for(int i=0;i<size;i++){
        if(data[i]==oldValue){
            data[i]=newValue;
            found = true;
            return;
        }
    }
    if(!found){
        std::cout<<"Value not found...\n";
    }
}

void StaticArray::reverse() {
    if (size<=1) return;
    int p_start=0;
    int p_end=size-1;
    while(p_start<p_end){
        int temp=data[p_start];
        data[p_start]=data[p_end];
        data[p_end]=temp;
        p_start++;
        p_end--;
    }
}

int StaticArray::findMiddle() const {
    if (data == NULL || size == 0) {
        std::cout << "Error: Array is empty or not initialized!" << std::endl;
        return 0;
    }
    return data[size / 2];
}

void StaticArray::removeDuplicates() {
    if (data == NULL || size <= 1) {
        return;
    }
    
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (data[i] == data[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            data[newSize] = data[i];
            newSize++;
        }
    }
    size = newSize;
    std::cout << "Duplicates removed successfully! New size: " << size << std::endl;
}

void StaticArray::swapElements(int pos1, int pos2) {
    if (data == NULL || size == 0) {
        std::cout << "Error: Array is empty or not initialized!" << std::endl;
        return;
    }
    
    if (pos1 < 0 || pos1 >= size || pos2 < 0 || pos2 >= size) {
        std::cout << "Error: Invalid positions! Positions must be between 0 and " << (size - 1) << std::endl;
        return;
    }
    
    if (pos1 == pos2) {
        std::cout << "Warning: Same positions provided, no swap needed." << std::endl;
        return;
    }
    
    int temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;
    
    std::cout << "Elements at positions " << pos1 << " and " << pos2 << " swapped successfully!" << std::endl;
}

int StaticArray::getSize() const {
    return size;
}

void StaticArray::sort() {
    if (data == NULL || size <= 1) {
        return;
    }
    
    // Bubble sort implementation
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Swap elements
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    
    std::cout << "Array sorted successfully in ascending order!" << std::endl;
}

// Advanced operations - TO BE IMPLEMENTED
StaticArray* StaticArray::clone() const {
    // TODO: Implement deep copy
    // Create and return a copy of current array
    return NULL;
}

bool StaticArray::compare(const Array& other) const {
    // TODO: Implement array comparison
    // Compare elements of two arrays
    return false;
}

StaticArray* StaticArray::mergeSorted(const Array& other) const {
    // TODO: Implement merge of two sorted arrays
    // Return new sorted array containing all elements
    return NULL;
}

void StaticArray::concatenate(const Array& other) {
    // TODO: Implement array concatenation
    // Append other array to current array
}

StaticArray* StaticArray::intersection(const Array& other) const {
    // TODO: Implement array intersection
    // Return array with common elements
    return NULL;
}

StaticArray* StaticArray::unionWith(const Array& other) const {
    // TODO: Implement array union
    // Return array with all unique elements
    return NULL;
}

StaticArray* StaticArray::difference(const Array& other) const {
    // TODO: Implement array difference
    // Return array with elements in current but not in other
    return NULL;
}

StaticArray* StaticArray::alternateMerge(const Array& other) const {
    // TODO: Implement alternate merging
    // Return array with alternating elements from both arrays
    return NULL;
}

void StaticArray::swapContents(Array& other) {
    // TODO: Implement content swapping
    // Swap contents of two arrays
}

void StaticArray::clear() {
    // TODO: Implement array clearing
    // Reset size to 0
}

bool StaticArray::isEmpty() const {
    // TODO: Check if array is empty
    return size == 0;
}

int StaticArray::getElementAt(int position) const {
    // TODO: Get element at specific position
    // Validate position and return element
    return 0;
}

void StaticArray::resize(int newSize) {
    // TODO: Implement array resizing
    // Note: Static arrays have fixed capacity, this might not be applicable
}

// Static array specific methods - TO BE IMPLEMENTED
bool StaticArray::isFull() const {
    // TODO: Check if array is at maximum capacity
    return size >= capacity;
}

int StaticArray::getCapacity() const {
    // TODO: Return maximum capacity
    return capacity;
}

void StaticArray::fill(int value) {
    // TODO: Fill entire array with given value
    // Set all elements to the specified value
}

void StaticArray::fillRange(int start, int end, int value) {
    // TODO: Fill range of array with given value
    // Fill elements from start to end with specified value
}
