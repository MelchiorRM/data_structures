#ifndef DOUBLYLINKED_HPP
#define DOUBLYLINKED_HPP

#include "LinkedList.hpp"
class DoublyLinked : public LinkedList {
    private:
        struct DoublyNode
        {
            int data;
            DoublyNode* prev_data;
            DoublyNode* next_data;
            DoublyNode(int value): data(value), prev_data(NULL), next_data(NULL) {}
        };
        DoublyNode* head;
        DoublyNode* tail;
    public:
        DoublyLinked();
        ~DoublyLinked();
        void insertAtBeginning(int value) override;
        void insertAtEnd(int value) override;
        void insertAtPosition(int value, int position) override;
        void deleteAtBeginning() override;
        void deleteAtEnd() override;
        void deleteAtPosition(int position) override;
        void createList(int size) override;
        void display() const override;
        bool search(int value) const override;
        void updateAtPosition(int position, int newValue) override;
        void updateNodeValue(int oldValue, int newValue) override;
        void reverse() override;
        int findMiddle() const override;
        void removeDuplicates() override;
        void swapNodes(int pos1, int pos2) override;
        int countNodes() const override;
        void sort() override;
        DoublyLinked* clone() const override;
        bool compare(const LinkedList& other) const override;
        DoublyLinked* mergeSorted(const LinkedList& other) const override;
        void concatenate(const LinkedList& other) override;
        DoublyLinked* intersection(const LinkedList& other) const override;
        DoublyLinked* unionWith(const LinkedList& other) const override;
        DoublyLinked* difference(const LinkedList& other) const override;
        DoublyLinked* alternateMerge(const LinkedList& other) const override;
        void swapContents(LinkedList& other) override;
        void free() override;
};
#endif