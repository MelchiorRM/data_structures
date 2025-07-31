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
void SinglyLinked::insertAtPosition(int value, int position){
    Node* newNode = new Node(value);
    if(position==0){
        insertAtBeginning(value);
        return;
    }
    Node* temp=head;
    for(int i=0;i<position-1 && temp !=nullptr;i++){
        temp=temp->next_data;
    }
    if(temp==nullptr){
        cout<<"Position is out of range...\n";
        delete newNode;
        return;
    }
    newNode->next_data=temp->next_data;
    temp->next_data=newNode;
}
void SinglyLinked::deleteAtBeginning(){
    if(head==nullptr){
        cout<<"Empty list, nothing to delete...\n";
        return;
    }
    Node* temp = head;
    head = head->next_data;
    delete temp;
}
void SinglyLinked::deleteAtEnd(){
    if(head==nullptr){
        cout<<"Empty list, nothing to delete...\n";
        return;
    }
    if(head->next_data==nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while(temp->next_data->next_data !=nullptr){
        temp = temp->next_data;
    }
    delete temp->next_data;
    temp->next_data=nullptr;
}
void SinglyLinked::deleteAtPosition(int position){
    if(head==nullptr){
         cout<<"Empty list, nothing to delete...\n";
        return;
    }
    if(position==0){
        deleteAtBeginning();
        return;
    }
    Node* temp=head;
    for(int i=0;i<position-1 && temp !=nullptr;i++){
        temp=temp->next_data;
    }
    if(temp->next_data==nullptr){
        cout<<"Position is out of range...\n";
        return;
    }
    Node* nodeToDelete = temp->next_data;
    temp->next_data = nodeToDelete->next_data;
    delete nodeToDelete;
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
bool SinglyLinked::search(int value) const{
    const Node* temp = head;
    while(temp!=nullptr){
        if(temp->data==value){
            return true;
        }
        temp=temp->next_data;
    }
    return false;
}
void SinglyLinked::updateAtPosition(int position, int newValue){
    Node* temp=head;
    int tempPosition=0;
    while(temp!=nullptr && tempPosition<position){
        temp=temp->next_data;
        tempPosition++;
    }
    if(temp!=nullptr){
        temp->data=newValue;
    } else {
        cout<<"Position is out range...\n";
    }
}
void SinglyLinked::updateNodeValue(int oldValue, int newValue){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data=oldValue){
            temp->data=newValue;
            return;
        }
        temp=temp->next_data;
    }
    cout<<"Value not found...\n";
}
void SinglyLinked::reverse() {
    Node* prev=nullptr;
    Node* next=nullptr;
    Node* temp=head;
    while(temp!=nullptr){
        next=temp->next_data;
        temp->next_data=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
}
int SinglyLinked::findMiddle() const {
    if(head==nullptr){
        return -1;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast->next_data!=nullptr && fast->next_data->next_data !=nullptr){
        slow=slow->next_data;
        fast=fast->next_data->next_data;
    }
    return slow->data;
}
void SinglyLinked::removeDuplicates() {
    Node* temp=head;
    while(temp!=nullptr){
        Node* checker=temp;
        while(checker->next_data!=nullptr){
            if(checker->next_data->data==temp->data){
                Node* currentNode = checker->next_data;
                checker->next_data = currentNode->next_data;
                delete currentNode;
            } else {
                checker = checker->next_data;
            }
        }
        temp=temp->next_data;
    }
}
void SinglyLinked::swapNodes(int pos1, int pos2) {
    if (pos1 == pos2) {
        cout << "Positions are the same, no swap needed...\n";
        return;
    }
    Node* prev1 = nullptr;
    Node* prev2 = nullptr;
    Node* temp1=head;
    Node* temp2=head;
    int count = 0;
    while (temp1 && count < pos1) {
        prev1 = temp1;
        temp1 = temp1->next_data;
        count++;
    }
    count = 0;
    while (temp2 && count < pos2) {
        prev2 = temp2;
        temp2 = temp2->next_data;
        count++;
    }
    if (!temp1 || !temp2) {
        cout << "One or both positions are out of range...\n";
        return;
    }
    if (prev1) {
        prev1->next_data = temp2;
    } else {
        head = temp2;
    }
    if (prev2) {
        prev2->next_data = temp1;
    } else {
        head = temp1;
    }
    Node* temp = temp1->next_data;
    temp1->next_data = temp2->next_data;
    temp2->next_data = temp;
}
int SinglyLinked::countNodes() const {
    int count = 0;
    Node* temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next_data;
    }
    return count;
}
void SinglyLinked::sort() {}
SinglyLinked* SinglyLinked::clone() const { return nullptr; }
bool SinglyLinked::compare(const LinkedList& other) const { return false; }
SinglyLinked* SinglyLinked::mergeSorted(const LinkedList& other) const { return nullptr; }
void SinglyLinked::concatenate(const LinkedList& other) {}
SinglyLinked* SinglyLinked::intersection(const LinkedList& other) const { return nullptr; }
SinglyLinked* SinglyLinked::unionWith(const LinkedList& other) const { return nullptr; }
SinglyLinked* SinglyLinked::difference(const LinkedList& other) const { return nullptr; }
SinglyLinked* SinglyLinked::alternateMerge(const LinkedList& other) const { return nullptr; }
void SinglyLinked::swapContents(LinkedList& other) {}
void SinglyLinked::free(){
    Node* temp;
    while(head!=nullptr) {
        temp = head;
        head = head->next_data;
        delete temp;
    }
}