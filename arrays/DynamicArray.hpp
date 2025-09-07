#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include "Array.hpp"

class DynamicArray : public Array {
    private:
        int* data;
        int size;
        int capacity;
        
    public:
        DynamicArray();
        DynamicArray(int initialCapacity);
        ~DynamicArray();
        
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
        DynamicArray* clone() const override;
        bool compare(const Array& other) const override;
        DynamicArray* mergeSorted(const Array& other) const override;
        void concatenate(const Array& other) override;
        DynamicArray* intersection(const Array& other) const override;
        DynamicArray* unionWith(const Array& other) const override;
        DynamicArray* difference(const Array& other) const override;
        DynamicArray* alternateMerge(const Array& other) const override;
        void swapContents(Array& other) override;
        void clear() override;
        bool isEmpty() const override;
        int getElementAt(int position) const override;
        void resize(int newSize) override;
        
        // Dynamic array specific methods
        void reserve(int newCapacity);
        void shrinkToFit();
        int getCapacity() const;
        void pushBack(int value);
        void popBack();
        int back() const;
        int front() const;
        void ensureCapacity(int requiredCapacity);
        void trimExcess();
};

#endif
