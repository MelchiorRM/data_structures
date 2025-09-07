#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array {
    public:
        virtual ~Array() = default;
        virtual void insertAtBeginning(int value) = 0;
        virtual void insertAtEnd(int value) = 0;
        virtual void insertAtPosition(int value, int position) = 0;
        virtual void deleteAtBeginning() = 0;
        virtual void deleteAtEnd() = 0;
        virtual void deleteAtPosition(int position) = 0;
        virtual void createArray(int size) = 0;
        virtual void display() const = 0;
        virtual bool search(int value) const = 0;
        virtual void updateAtPosition(int position, int newValue) = 0;
        virtual void updateValue(int oldValue, int newValue) = 0;
        virtual void reverse() = 0;
        virtual int findMiddle() const = 0;
        virtual void removeDuplicates() = 0;
        virtual void swapElements(int pos1, int pos2) = 0;
        virtual int getSize() const = 0;
        virtual void sort() = 0;
        virtual Array* clone() const = 0;
        virtual bool compare(const Array& other) const = 0;
        virtual Array* mergeSorted(const Array& other) const = 0;
        virtual void concatenate(const Array& other) = 0;
        virtual Array* intersection(const Array& other) const = 0;
        virtual Array* unionWith(const Array& other) const = 0;
        virtual Array* difference(const Array& other) const = 0;
        virtual Array* alternateMerge(const Array& other) const = 0;
        virtual void swapContents(Array& other) = 0;
        virtual void clear() = 0;
        virtual bool isEmpty() const = 0;
        virtual int getElementAt(int position) const = 0;
        virtual void resize(int newSize) = 0;
};

#endif
