#include <iostream>
#include "SinglyLinked.hpp"
using namespace std;

SinglyLinked::SinglyLinked() : head(nullptr) {}
SinglyLinked::~SinglyLinked() {
    free();
}
void SinglyLinked::insertAtBeginning(int value){
    Node* newNode = new Node(value);
    newNode->next_data = head;
    head = newNode;
}
void SinglyLinked::insertAtEnd(int value){
    Node* newNode = new Node(value);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next_data != nullptr){
        temp = temp->next_data;
    }
    temp->next_data = newNode;

}
void SinglyLinked::createList(int size) {
    Node* head = nullptr;
    int value;
    cout<<"Enter the size of the list: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter the value of node "<<i+1<<" : ";
        cin>>value;
        insertAtEnd(value);
    }
}
void SinglyLinked::display() const {
    if(head==nullptr) {
        cout<<"The list is empty\n";
        return;
    }
    Node* temp = head;
    cout<<"List: ";
    while(temp){
        cout<<temp->data<<" -> ";
        temp=temp->next_data;
    }
    cout<<"NULL\n";
}
void SinglyLinked::free(){
    Node* temp;
    while(head!=nullptr) {
        temp = head;
        head = head->next_data;
        delete temp;
    }
}