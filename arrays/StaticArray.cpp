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

// Destructor
StaticArray::~StaticArray() {
    delete[] data;
}

// Basic operations - TO BE IMPLEMENTED
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
        std::cout << "Error: Array is full! Cannot insert at beginning.\n";
        return;
    }
    data[size]=value;
    size++;
    std::cout << "Value " << value << " inserted at ending successfully!\n";
}

void StaticArray::insertAtPosition(int value, int position) {
    // TODO: Implement insertion at specific position
    // Validate position, shift elements, and insert
}

void StaticArray::deleteAtBeginning() {
    // TODO: Implement deletion at beginning
    // Shift all elements to the left
}

void StaticArray::deleteAtEnd() {
    // TODO: Implement deletion at end
    // Simply decrement size
}

void StaticArray::deleteAtPosition(int position) {
    // TODO: Implement deletion at specific position
    // Validate position, shift elements left
}

void StaticArray::createArray(int size) {
    // TODO: Implement array creation
    // Allocate memory and initialize
}

void StaticArray::display() const {
    // TODO: Implement display functionality
    // Print all elements in the array
}

bool StaticArray::search(int value) const {
    // TODO: Implement linear search
    // Return true if value found, false otherwise
    return false;
}

void StaticArray::updateAtPosition(int position, int newValue) {
    // TODO: Implement update at specific position
    // Validate position and update value
}

void StaticArray::updateValue(int oldValue, int newValue) {
    // TODO: Implement update by value
    // Find first occurrence and update
}

void StaticArray::reverse() {
    // TODO: Implement array reversal
    // Reverse elements in place
}

int StaticArray::findMiddle() const {
    // TODO: Implement find middle element
    // Return middle element value
    return 0;
}

void StaticArray::removeDuplicates() {
    // TODO: Implement duplicate removal
    // Remove duplicate elements while maintaining order
}

void StaticArray::swapElements(int pos1, int pos2) {
    // TODO: Implement element swapping
    // Swap elements at given positions
}

int StaticArray::getSize() const {
    // TODO: Return current size
    return size;
}

void StaticArray::sort() {
    // TODO: Implement sorting algorithm
    // Sort array in ascending order
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
