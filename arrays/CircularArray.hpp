#ifndef CIRCULARARRAY_HPP
#define CIRCULARARRAY_HPP

#include "Array.hpp"

class CircularArray : public Array {
    private:
        int* data;
        int size;
        int capacity;
        int front;
        int rear;
        
    public:
        CircularArray();
        CircularArray(int initialCapacity);
        ~CircularArray();
        
        // Basic operations
        void insertAtBeginning(int value) override;
        void insertAtEnd(int value) override;
        void insertAtPosition(int value, int position) override;
        void deleteAtBeginning() override;
        void deleteAtEnd() override;
        void deleteAtPosition(int position) override;
        void createArray(int size) override;
        void display() const override;
        bool search(int value) const override;
        void updateAtPosition(int position, int newValue) override;
        void updateValue(int oldValue, int newValue) override;
        void reverse() override;
        int findMiddle() const override;
        void removeDuplicates() override;
        void swapElements(int pos1, int pos2) override;
        int getSize() const override;
        void sort() override;
        
        // Advanced operations
        CircularArray* clone() const override;
        bool compare(const Array& other) const override;
        CircularArray* mergeSorted(const Array& other) const override;
        void concatenate(const Array& other) override;
        CircularArray* intersection(const Array& other) const override;
        CircularArray* unionWith(const Array& other) const override;
        CircularArray* difference(const Array& other) const override;
        CircularArray* alternateMerge(const Array& other) const override;
        void swapContents(Array& other) override;
        void clear() override;
        bool isEmpty() const override;
        int getElementAt(int position) const override;
        void resize(int newSize) override;
        
        // Circular array specific methods
        bool isFull() const;
        int getCapacity() const;
        void enqueue(int value);
        int dequeue();
        int peek() const;
        void rotate(int steps);
        void rotateLeft(int steps);
        void rotateRight(int steps);
        int getFront() const;
        int getRear() const;
        void reset();
};

#endif
