#include "CircularLinked.hpp"
#include <iostream>
using namespace std;

CircularLinked::CircularLinked() : head(nullptr) {}
CircularLinked::~CircularLinked() { free(); }

void CircularLinked::insertAtBeginning(int value) {}
void CircularLinked::insertAtEnd(int value) {}
void CircularLinked::insertAtPosition(int value, int position) {}
void CircularLinked::deleteAtBeginning() {}
void CircularLinked::deleteAtEnd() {}
void CircularLinked::deleteAtPosition(int position) {}
void CircularLinked::createList(int size) {}
void CircularLinked::display() const {}
bool CircularLinked::search(int value) const { return false; }
void CircularLinked::updateAtPosition(int position, int newValue) {}
void CircularLinked::updateNodeValue(int oldValue, int newValue) {}
void CircularLinked::reverse() {}
int CircularLinked::findMiddle() const { return 0; }
void CircularLinked::removeDuplicates() {}
void CircularLinked::swapNodes(int pos1, int pos2) {}
int CircularLinked::countNodes() const { return 0; }
void CircularLinked::sort() {}
CircularLinked* CircularLinked::clone() const { return nullptr; }
bool CircularLinked::compare(const LinkedList& other) const { return false; }
CircularLinked* CircularLinked::mergeSorted(const LinkedList& other) const { return nullptr; }
void CircularLinked::concatenate(const LinkedList& other) {}
CircularLinked* CircularLinked::intersection(const LinkedList& other) const { return nullptr; }
CircularLinked* CircularLinked::unionWith(const LinkedList& other) const { return nullptr; }
CircularLinked* CircularLinked::difference(const LinkedList& other) const { return nullptr; }
CircularLinked* CircularLinked::alternateMerge(const LinkedList& other) const { return nullptr; }
void CircularLinked::swapContents(LinkedList& other) {}
void CircularLinked::free() {}
