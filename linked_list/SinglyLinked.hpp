#ifndef SINGLYLINKED_HPP
#define SINGLYLINKED_HPP

#include "LinkedList.hpp"

class SinglyLinked : public LinkedList {
    private:
        struct Node
        {
            int data;
            Node* next_data;
            Node(int value): data(value), next_data(nullptr) {}
        };
        Node* head;
    public:
        SinglyLinked();
        ~SinglyLinked();
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
        SinglyLinked* clone() const override;
        bool compare(const LinkedList& other) const override;
        SinglyLinked* mergeSorted(const LinkedList& other) const override;
        void concatenate(const LinkedList& other) override;
        SinglyLinked* intersection(const LinkedList& other) const override;
        SinglyLinked* unionWith(const LinkedList& other) const override;
        SinglyLinked* difference(const LinkedList& other) const override;
        SinglyLinked* alternateMerge(const LinkedList& other) const override;
        void swapContents(LinkedList& other) override;
        void free();
};
#endif