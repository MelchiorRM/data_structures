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
        void search(int value) const override;
        void updateAtPosition(int position, int newValue) override;
        void updateNodeValue(int oldValue, int newValue) override;
        void free();
};
#endif