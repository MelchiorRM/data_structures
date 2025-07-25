#include "DoublyLinked.hpp"
#include <iostream>
using namespace std;

DoublyLinked::DoublyLinked() : head(nullptr), tail(nullptr) {}
DoublyLinked::~DoublyLinked() { free(); }

void DoublyLinked::insertAtBeginning(int value) {}
void DoublyLinked::insertAtEnd(int value) {}
void DoublyLinked::insertAtPosition(int value, int position) {}
void DoublyLinked::deleteAtBeginning() {}
void DoublyLinked::deleteAtEnd() {}
void DoublyLinked::deleteAtPosition(int position) {}
void DoublyLinked::createList(int size) {}
void DoublyLinked::display() const {}
bool DoublyLinked::search(int value) const { return false; }
void DoublyLinked::updateAtPosition(int position, int newValue) {}
void DoublyLinked::updateNodeValue(int oldValue, int newValue) {}
void DoublyLinked::reverse() {}
int DoublyLinked::findMiddle() const { return 0; }
void DoublyLinked::removeDuplicates() {}
void DoublyLinked::swapNodes(int pos1, int pos2) {}
int DoublyLinked::countNodes() const { return 0; }
void DoublyLinked::sort() {}
DoublyLinked* DoublyLinked::clone() const { return nullptr; }
bool DoublyLinked::compare(const LinkedList& other) const { return false; }
DoublyLinked* DoublyLinked::mergeSorted(const LinkedList& other) const { return nullptr; }
void DoublyLinked::concatenate(const LinkedList& other) {}
DoublyLinked* DoublyLinked::intersection(const LinkedList& other) const { return nullptr; }
DoublyLinked* DoublyLinked::unionWith(const LinkedList& other) const { return nullptr; }
DoublyLinked* DoublyLinked::difference(const LinkedList& other) const { return nullptr; }
DoublyLinked* DoublyLinked::alternateMerge(const LinkedList& other) const { return nullptr; }
void DoublyLinked::swapContents(LinkedList& other) {}
void DoublyLinked::free() {}