#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "SinglyLinked.hpp"
using namespace std;

SinglyLinked::SinglyLinked() : head(NULL) {}
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
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next_data != NULL){
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
    for(int i=0;i<position-1 && temp !=NULL;i++){
        temp=temp->next_data;
    }
    if(temp==NULL){
        cout<<"Position is out of range...\n";
        delete newNode;
        return;
    }
    newNode->next_data=temp->next_data;
    temp->next_data=newNode;
}
void SinglyLinked::deleteAtBeginning(){
    if(head==NULL){
        cout<<"Empty list, nothing to delete...\n";
        return;
    }
    Node* temp = head;
    head = head->next_data;
    delete temp;
}
void SinglyLinked::deleteAtEnd(){
    if(head==NULL){
        cout<<"Empty list, nothing to delete...\n";
        return;
    }
    if(head->next_data==NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next_data->next_data !=NULL){
        temp = temp->next_data;
    }
    delete temp->next_data;
    temp->next_data=NULL;
}
void SinglyLinked::deleteAtPosition(int position){
    if(head==NULL){
         cout<<"Empty list, nothing to delete...\n";
        return;
    }
    if(position==0){
        deleteAtBeginning();
        return;
    }
    Node* temp=head;
    for(int i=0;i<position-1 && temp !=NULL;i++){
        temp=temp->next_data;
    }
    if(temp->next_data==NULL){
        cout<<"Position is out of range...\n";
        return;
    }
    Node* nodeToDelete = temp->next_data;
    temp->next_data = nodeToDelete->next_data;
    delete nodeToDelete;
}
void SinglyLinked::createList(int size) {
    Node* head = NULL;
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
    if(head==NULL) {
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
    while(temp!=NULL){
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
    while(temp!=NULL && tempPosition<position){
        temp=temp->next_data;
        tempPosition++;
    }
    if(temp!=NULL){
        temp->data=newValue;
    } else {
        cout<<"Position is out range...\n";
    }
}
void SinglyLinked::updateNodeValue(int oldValue, int newValue){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data=oldValue){
            temp->data=newValue;
            return;
        }
        temp=temp->next_data;
    }
    cout<<"Value not found...\n";
}
void SinglyLinked::reverse() {
    Node* prev=NULL;
    Node* next=NULL;
    Node* temp=head;
    while(temp!=NULL){
        next=temp->next_data;
        temp->next_data=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
}
int SinglyLinked::findMiddle() const {
    if(head==NULL){
        return -1;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast->next_data!=NULL && fast->next_data->next_data !=NULL){
        slow=slow->next_data;
        fast=fast->next_data->next_data;
    }
    return slow->data;
}
void SinglyLinked::removeDuplicates() {
    Node* temp=head;
    while(temp!=NULL){
        Node* checker=temp;
        while(checker->next_data!=NULL){
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
    Node* prev1 = NULL;
    Node* prev2 = NULL;
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
    while(temp!=NULL){
        count++;
        temp=temp->next_data;
    }
    return count;
}
void SinglyLinked::sort() {}
SinglyLinked* SinglyLinked::clone() const { return NULL; }
bool SinglyLinked::compare(const LinkedList& other) const { return false; }
SinglyLinked* SinglyLinked::mergeSorted(const LinkedList& other) const { return NULL; }
void SinglyLinked::concatenate(const LinkedList& other) {}
SinglyLinked* SinglyLinked::intersection(const LinkedList& other) const { return NULL; }
SinglyLinked* SinglyLinked::unionWith(const LinkedList& other) const { return NULL; }
SinglyLinked* SinglyLinked::difference(const LinkedList& other) const { return NULL; }
SinglyLinked* SinglyLinked::alternateMerge(const LinkedList& other) const { return NULL; }
void SinglyLinked::swapContents(LinkedList& other) {}
void SinglyLinked::free(){
    Node* temp;
    while(head!=NULL) {
        temp = head;
        head = head->next_data;
        delete temp;
    }
}