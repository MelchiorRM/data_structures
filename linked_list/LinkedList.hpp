#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
class LinkedList {
    public:
        virtual void insertAtBeginning(int value)=0;
        virtual void insertAtEnd(int value)=0;
        virtual void createList(int size)=0;
        virtual void display() const = 0;
        virtual void free()=0;
        virtual ~LinkedList() = default;
};
#endif