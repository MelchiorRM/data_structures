#include <iostream>
#include <memory>
#include "LinkedList.hpp"
#include "SinglyLinked.hpp"
#include "DoublyLinked.hpp"
#include "CircularLinked.hpp"

using namespace std;
void showMenu();
void editMenu();
void intermediateMenu();
void listToListMenu();
void selectListMenu();
void editMenuHandler();
void selectMenuHandler();
void intermediateMenuHandler();
void listToListMenuHandler();
LinkedList* currentList = nullptr;

void showMenu(){
    cout<<"\n--- Linked List Operations Menu ---\n";
    cout<<"1. Create a new linked list\n";
    cout<<"2. Select/switch current list\n";
    cout<<"3. Display current list\n";
    cout<<"4. Edit current list\n";
    cout<<"5. Peform intermediate operations\n";
    cout<<"6. List-to-list operations\n";
    cout<<"7. Delete a linked list\n";
    cout<<"0. Exit\n";
    cout<<"Choice: ";
}
void selectListMenu() {
    cout<<"\n---Select Linked List---\n";
    cout<<"1. Singly Linked List\n";
    cout<<"2. Doubly Linked List\n";
    cout<<"3. Circular Linked List\n";
    cout<<"Choice: ";
}
void selectListHandler() {
    int choice;
    selectListMenu();
    cin >> choice;
    if (currentList) {
        currentList->free();
        delete currentList;
        currentList = nullptr;
    }
    switch(choice) {
        case 1:
            currentList = new SinglyLinked();
            cout << "Singly Linked List selected.\n";
            break;
        case 2:
            currentList = new DoublyLinked();
            cout << "Doubly Linked List selected.\n";
            break;
        case 3:
            currentList = new CircularLinked();
            cout << "Circular Linked List selected.\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }
}
void editMenu(){
    cout<<"\n---Edit linked list---\n";
    cout<<"1. Insert at Beginning\n";
    cout<<"2. Insert at End\n";
    cout<<"3. Insert at Position\n";
    cout<<"4. Delete at Beginning\n";
    cout<<"5. Delete at End\n";
    cout<<"6. Delete at Position\n";
    cout<<"7. Search for Element\n";
    cout<<"8. Update Node by Value\n";
    cout<<"9. Update Node by Position\n";
    cout<<"10. Count Nodes\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}
void editMenuHandler(){
    if (!currentList) {
        cout << "No list selected. Please create or select a list first.\n";
        return;
    }
    int editChoice;
    while(true) {
        editMenu();
        cin>>editChoice;
        switch(editChoice){
            case 1:
                cout<<"Insert value at Beginning: ";
                int valueAtBeginning;
                cin>>valueAtBeginning;
                cout<<"\n";
                currentList->insertAtBeginning(valueAtBeginning);
                currentList->display();
                cout<<"\n";
                break;
            case 2:
                cout<<"Insert value at End: ";
                int valueAtEnd;
                cin>>valueAtEnd;
                cout<<"\n";
                currentList->insertAtEnd(valueAtEnd);
                currentList->display();
                cout<<"\n";
                break;
            case 3:
                cout<<"Insert at a chosen position....\n";
                {
                int position,value;
                cout<<"Enter the position where you want to add a new value: ";
                cin>>position;
                cout<<"\n";
                cout<<"Enter the value: ";
                cin>>value;
                cout<<"\n";
                currentList->insertAtPosition(value,position);
                currentList->display();
                }
                break;
            case 4:
                cout<<"Delete at the Beginning...\n";
                currentList->deleteAtBeginning();
                currentList->display();
                break;
            case 5:
                cout<<"Delete at the End...\n";
                currentList->deleteAtEnd();
                currentList->display();
                cout<<"\n";
                break;
            case 6:
                cout<<"Delete at a chosen position...\n";
                {
                int position;
                cin>>position;
                cout<<"\n";
                currentList->deleteAtPosition(position);
                currentList->display();
                }
                break;
            case 7:
                cout<<"Search if a value exists in the list...\n";
                {
                    int value;
                    cout<<"Enter the value to be searched: ";
                    cin>>value;
                    cout<<"\n";
                    if(currentList->search(value)){
                        cout<<value<<" is found in the list.\n";
                    }
                    else{
                        cout<<value<<" is not found in the list.\n";
                    }
                }
                break;
            case 8:
                cout<<"Update One Node by Value...\n";
                {
                    int oldV,newV;
                    cout<<"Enter old value that you want to change: \n";
                    cin>>oldV;
                    cout<<"\n";
                    cout<<"Enter the new value of that node: ";
                    cin>>newV;
                    cout<<"\n";
                    currentList->updateNodeValue(oldV,newV);
                    currentList->display();
                }
                break;
            case 9:
                cout<<"Update one Node by Position...\n";
                {
                    int position,newV;
                    cout<<"Enter the position of the old value that you want to change: \n";
                    cin>>position;
                    cout<<"\n";
                    cout<<"Enter the new value of that node: ";
                    cin>>newV;
                    cout<<"\n";
                    currentList->updateAtPosition(position,newV);
                    currentList->display();
                }
                break;
            case 10:
                cout<<"Count the numbers of nodes in the linked list...\n";
                cout<<"The current list has "<<currentList->countNodes()<<" nodes\n";
                break;
            case 0:
                return;
            default:
                cout<<"Invalid choice...\n";
                break;
        }
    }
}
void intermediateMenu(){
    cout<<"\n---Intermediate operations---\n";
    cout<<"1. Find Middle Node\n";
    cout<<"2. Remove duplicates\n";
    cout<<"3. Swap two nodes\n";
    cout<<"4. Reverse List\n";
    cout<<"5. Sort List\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}
void intermediateMenuHandler() {
    if (!currentList) {
        cout << "No list selected. Please create or select a list first.\n";
        return;
    }
    
    int choice;
    while (true) {
        intermediateMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Finding middle node...\n";
                {
                    int middleValue = currentList->findMiddle();
                    if (middleValue != -1) {
                        cout << "Middle node value: " << middleValue << "\n";
                    } else {
                        cout << "List is empty or has no middle node.\n";
                    }
                }
                break;
            case 2:
                cout << "Removing duplicates...\n";
                currentList->removeDuplicates();
                cout << "Duplicates removed. Current list: \n";
                currentList->display();
                break;
            case 3:
                cout << "Swap two nodes...\n";
                {
                    int pos1, pos2;
                    cout << "Enter first position: ";
                    cin >> pos1;
                    cout << "Enter second position: ";
                    cin >> pos2;
                    currentList->swapNodes(pos1, pos2);
                    cout << "Nodes swapped. Current list: \n";
                    currentList->display();
                }
                break;
            case 4:
                cout << "Reversing list...\n";
                currentList->reverse();
                cout << "List reversed. Current list: \n";
                currentList->display();
                break;
            case 5:
                cout << "Sorting list...\n";
                currentList->sort();
                cout << "List sorted. Current list: \n";
                currentList->display();
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
void listToListMenu(){
    cout<<"\n--- List-to-List Operations ---\n";
    cout<<"1. Concatenate Two Lists \n";
    cout<<"2. Copy/Clone a List\n";
    cout<<"3. Merge Two Sorted Lists\n";
    cout<<"4. Compare Two Lists\n";
    cout<<"5. Intersection of Two Lists\n";
    cout<<"6. Union of Two Lists \n";
    cout<<"7. Difference of Two Lists\n";
    cout<<"8. Alternate Merge\n";
    cout<<"9. Swap Contents\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}
void listToListMenuHandler() {
    int choice;
    while (true) {
        listToListMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Concatenate Two Lists: Not implemented yet...\n";
                break;
            case 2:
                cout << "Copy/Clone a List: Not implemented yet.\n";
                break;
            case 3:
                cout << "Merge Two Sorted Lists: Not implemented yet.\n";
                break;
            case 4:
                cout << "Compare Two Lists: Not implemented yet.\n";
                break;
            case 5:
                cout << "Intersection of Two Lists: Not implemented yet.\n";
                break;
            case 6:
                cout << "Union of Two Lists: Not implemented yet.\n";
                break;
            case 7:
                cout << "Difference of Two Lists: Not implemented yet.\n";
                break;
            case 8:
                cout << "Alternate Merge: Not implemented yet.\n";
                break;
            case 9:
                cout << "Swap Contents: Not implemented yet.\n";
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

int main(){
    int mainChoice;
    do{
        showMenu();
        cin>>mainChoice;
        switch(mainChoice){
            case 1:
                selectListHandler();
                if (currentList) {
                    currentList->createList(0);
                }
                break;
            case 2:
                selectListHandler();
                break;
            case 3:
                if (currentList) {
                    cout<<"Displaying the current linked list...\n";
                    currentList->display();
                } else {
                    cout<<"No list selected.\n";
                }
                break;
            case 4:
                editMenuHandler();
                break;
            case 5:
                intermediateMenuHandler();
                break;
            case 6:
                // TODO: update listToListMenuHandler to use currentList
                break;
            case 7:
                if (currentList) {
                    currentList->free();
                    delete currentList;
                    currentList = nullptr;
                    cout << "Current list deleted.\n";
                } else {
                    cout << "No list to delete.\n";
                }
                break;
            default:
                cout<<"Invalid choice...\n";
        }
    } while (mainChoice !=0);
    if (currentList) {
        currentList->free();
        delete currentList;
    }
    return 0;
}