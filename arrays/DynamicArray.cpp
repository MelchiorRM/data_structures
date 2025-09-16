#include "DynamicArray.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>

// Constructor
DynamicArray::DynamicArray() : data(NULL), size(0), capacity(0) {}

DynamicArray::DynamicArray(int initialCapacity) : data(NULL), size(0), capacity(0) {
    if (initialCapacity > 0) {
        data = new int[initialCapacity];
        capacity = initialCapacity;
    }
}

// Destructor
DynamicArray::~DynamicArray() {
    delete[] data;
}

// Basic operations - TO BE IMPLEMENTED
void DynamicArray::insertAtBeginning(int value) {
    ensureCapacity(size + 1);
    
    // Shift all elements to the right
    for (int i = size; i > 0; i--) {
        data[i] = data[i - 1];
    }
    
    // Insert at beginning
    data[0] = value;
    size++;
    
    std::cout << "Value " << value << " inserted at beginning successfully!" << std::endl;
}

void DynamicArray::insertAtEnd(int value) {
    ensureCapacity(size + 1);
    
    // Insert at end
    data[size] = value;
    size++;
    
    std::cout << "Value " << value << " inserted at end successfully!" << std::endl;
}

void DynamicArray::insertAtPosition(int value, int position) {
    if (position < 0 || position > size) {
        std::cout << "Error: Invalid position! Position must be between 0 and " << size << std::endl;
        return;
    }
    
    ensureCapacity(size + 1);
    
    // Shift elements to the right from position onwards
    for (int i = size; i > position; i--) {
        data[i] = data[i - 1];
    }
    
    // Insert at position
    data[position] = value;
    size++;
    
    std::cout << "Value " << value << " inserted at position " << position << " successfully!" << std::endl;
}

void DynamicArray::deleteAtBeginning() {
    if (size <= 0) {
        std::cout << "Error: Array is empty! Cannot delete from beginning." << std::endl;
        return;
    }
    
    // Shift all elements to the left
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    
    size--;
    std::cout << "Element deleted from beginning successfully!" << std::endl;
}

void DynamicArray::deleteAtEnd() {
    if (size <= 0) {
        std::cout << "Error: Array is empty! Cannot delete from end." << std::endl;
        return;
    }
    
    size--;
    std::cout << "Element deleted from end successfully!" << std::endl;
}

void DynamicArray::deleteAtPosition(int position) {
    if (size <= 0) {
        std::cout << "Error: Array is empty! Cannot delete from any position." << std::endl;
        return;
    }
    
    if (position < 0 || position >= size) {
        std::cout << "Error: Invalid position! Position must be between 0 and " << (size - 1) << std::endl;
        return;
    }
    
    // Shift elements to the left from position onwards
    for (int i = position; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    
    size--;
    std::cout << "Element deleted from position " << position << " successfully!" << std::endl;
}

void DynamicArray::createArray(int size) {
    if (size <= 0) {
        std::cout << "Error: Invalid size! Size must be positive." << std::endl;
        return;
    }
    
    // Clean up existing data
    if (data != NULL) {
        delete[] data;
    }
    
    // Allocate new memory
    data = new int[size];
    if (data == NULL) {
        std::cout << "Error: Memory allocation failed!" << std::endl;
        return;
    }
    
    this->size = 0;
    this->capacity = size;
    
    // Initialize with zeros
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
    
    std::cout << "Dynamic array created successfully with capacity " << size << std::endl;
}

void DynamicArray::display() const {
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

bool DynamicArray::search(int value) const {
    if (data == NULL || size == 0) {
        return false;
    }
    
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

void DynamicArray::updateAtPosition(int position, int newValue) {
    if (data == NULL || size == 0) {
        std::cout << "Error: Array is empty or not initialized!" << std::endl;
        return;
    }
    
    if (position < 0 || position >= size) {
        std::cout << "Error: Invalid position! Position must be between 0 and " << (size - 1) << std::endl;
        return;
    }
    
    data[position] = newValue;
    std::cout << "Element at position " << position << " updated to " << newValue << " successfully!" << std::endl;
}

void DynamicArray::updateValue(int oldValue, int newValue) {
    if (data == NULL || size == 0) {
        std::cout << "Error: Array is empty or not initialized!" << std::endl;
        return;
    }
    
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (data[i] == oldValue) {
            data[i] = newValue;
            found = true;
            std::cout << "First occurrence of " << oldValue << " updated to " << newValue << " at position " << i << std::endl;
            return;
        }
    }
    
    if (!found) {
        std::cout << "Value " << oldValue << " not found in array!" << std::endl;
    }
}

void DynamicArray::reverse() {
    if (data == NULL || size <= 1) {
        return;
    }
    
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        int temp = data[start];
        data[start] = data[end];
        data[end] = temp;
        start++;
        end--;
    }
    
    std::cout << "Array reversed successfully!" << std::endl;
}

int DynamicArray::findMiddle() const {
    if (data == NULL || size == 0) {
        std::cout << "Error: Array is empty or not initialized!" << std::endl;
        return 0;
    }
    return data[size / 2];
}

void DynamicArray::removeDuplicates() {
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

void DynamicArray::swapElements(int pos1, int pos2) {
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

int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::sort() {
    if (data == NULL || size <= 1) {
        return;
    }
    
    // Bubble sort implementation
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
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
DynamicArray* DynamicArray::clone() const {
    // TODO: Implement deep copy
    // Create and return a copy of current array
    return NULL;
}

bool DynamicArray::compare(const Array& other) const {
    // TODO: Implement array comparison
    // Compare elements of two arrays
    return false;
}

DynamicArray* DynamicArray::mergeSorted(const Array& other) const {
    // TODO: Implement merge of two sorted arrays
    // Return new sorted array containing all elements
    return NULL;
}

void DynamicArray::concatenate(const Array& other) {
    // TODO: Implement array concatenation
    // Append other array to current array
}

DynamicArray* DynamicArray::intersection(const Array& other) const {
    // TODO: Implement array intersection
    // Return array with common elements
    return NULL;
}

DynamicArray* DynamicArray::unionWith(const Array& other) const {
    // TODO: Implement array union
    // Return array with all unique elements
    return NULL;
}

DynamicArray* DynamicArray::difference(const Array& other) const {
    // TODO: Implement array difference
    // Return array with elements in current but not in other
    return NULL;
}

DynamicArray* DynamicArray::alternateMerge(const Array& other) const {
    // TODO: Implement alternate merging
    // Return array with alternating elements from both arrays
    return NULL;
}

void DynamicArray::swapContents(Array& other) {
    // TODO: Implement content swapping
    // Swap contents of two arrays
}

void DynamicArray::clear() {
    // TODO: Implement array clearing
    // Reset size to 0
}

bool DynamicArray::isEmpty() const {
    // TODO: Check if array is empty
    return size == 0;
}

int DynamicArray::getElementAt(int position) const {
    // TODO: Get element at specific position
    // Validate position and return element
    return 0;
}

void DynamicArray::resize(int newSize) {
    // TODO: Implement array resizing
    // Allocate new memory, copy elements, update capacity
}

// Dynamic array specific methods - TO BE IMPLEMENTED
void DynamicArray::reserve(int newCapacity) {
    // TODO: Reserve capacity without changing size
    // Allocate new memory if needed, copy existing elements
}

void DynamicArray::shrinkToFit() {
    // TODO: Reduce capacity to match current size
    // Reallocate memory to exact size needed
}

int DynamicArray::getCapacity() const {
    // TODO: Return current capacity
    return capacity;
}

void DynamicArray::pushBack(int value) {
    // TODO: Add element to end (similar to insertAtEnd)
    // Ensure capacity and add element
}

void DynamicArray::popBack() {
    // TODO: Remove last element (similar to deleteAtEnd)
    // Decrement size
}

int DynamicArray::back() const {
    // TODO: Return last element
    // Return element at size-1 position
    return 0;
}

int DynamicArray::front() const {
    // TODO: Return first element
    // Return element at index 0
    return 0;
}

void DynamicArray::ensureCapacity(int requiredCapacity) {
    if (requiredCapacity <= capacity) {
        return; // Already has enough capacity
    }
    
    // Calculate new capacity (double current capacity or use required capacity)
    int newCapacity = (capacity == 0) ? 1 : capacity;
    while (newCapacity < requiredCapacity) {
        newCapacity *= 2;
    }
    
    // Allocate new memory
    int* newData = new int[newCapacity];
    
    // Copy existing elements
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    
    // Delete old memory and update pointers
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void DynamicArray::trimExcess() {
    // TODO: Trim excess capacity
    // Similar to shrinkToFit but with different threshold
}
