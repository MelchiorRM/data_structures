#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
class LinkedList {
    public:
        virtual void insertAtBeginning(int value)=0;
        virtual void insertAtEnd(int value)=0;
        virtual void insertAtPosition(int value, int position)=0;
        virtual void deleteAtBeginning() = 0;
        virtual void deleteAtEnd() = 0;
        virtual void deleteAtPosition(int position) = 0;
        virtual void createList(int size)=0;
        virtual void display() const = 0;
        virtual void search(int value) const = 0;
        virtual void updateAtPosition(int position, int newValue)=0;
        virtual void updateNodeValue(int oldValue, int newValue)=0;
        virtual void free()=0;
        virtual ~LinkedList() = default;
};
#endif