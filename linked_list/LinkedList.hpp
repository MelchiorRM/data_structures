#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
class LinkedList {
    public:
        virtual ~LinkedList() = default;
        virtual void insertAtBeginning(int value)=0;
        virtual void insertAtEnd(int value)=0;
        virtual void insertAtPosition(int value, int position)=0;
        virtual void deleteAtBeginning() = 0;
        virtual void deleteAtEnd() = 0;
        virtual void deleteAtPosition(int position) = 0;
        virtual void createList(int size)=0;
        virtual void display() const = 0;
        virtual bool search(int value) const = 0;
        virtual void updateAtPosition(int position, int newValue)=0;
        virtual void updateNodeValue(int oldValue, int newValue)=0;
        virtual void reverse() = 0;
        virtual int findMiddle() const = 0;
        virtual void removeDuplicates() = 0;
        virtual void swapNodes(int pos1, int pos2) = 0;
        virtual int countNodes() const = 0;
        virtual void sort() = 0;
        virtual LinkedList* clone() const = 0;
        virtual bool compare(const LinkedList& other) const = 0;
        virtual LinkedList* mergeSorted(const LinkedList& other) const = 0;
        virtual void concatenate(const LinkedList& other) = 0;
        virtual LinkedList* intersection(const LinkedList& other) const = 0;
        virtual LinkedList* unionWith(const LinkedList& other) const = 0;
        virtual LinkedList* difference(const LinkedList& other) const = 0;
        virtual LinkedList* alternateMerge(const LinkedList& other) const = 0;
        virtual void swapContents(LinkedList& other) = 0;
        virtual void free()=0;
};
#endif