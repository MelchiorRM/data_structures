#ifndef STATICARRAY_HPP
#define STATICARRAY_HPP

#include "Array.hpp"

class StaticArray : public Array {
    private:
        static const int MAX_SIZE = 1000;  // Maximum size for static array
        int* data;
        int size;
        int capacity;
        
    public:
        StaticArray();
        StaticArray(int initialCapacity);
        ~StaticArray();
        
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
        StaticArray* clone() const override;
        bool compare(const Array& other) const override;
        StaticArray* mergeSorted(const Array& other) const override;
        void concatenate(const Array& other) override;
        StaticArray* intersection(const Array& other) const override;
        StaticArray* unionWith(const Array& other) const override;
        StaticArray* difference(const Array& other) const override;
        StaticArray* alternateMerge(const Array& other) const override;
        void swapContents(Array& other) override;
        void clear() override;
        bool isEmpty() const override;
        int getElementAt(int position) const override;
        void resize(int newSize) override;
        
        // Static array specific methods
        bool isFull() const;
        int getCapacity() const;
        void fill(int value);
        void fillRange(int start, int end, int value);
};

#endif
