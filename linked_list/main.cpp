#include <iostream>
#include <memory>
#include "LinkedList.hpp"
#include "SinglyLinked.hpp"
using namespace std;
void showMenu();
void editMenu();
void intermediateMenu();
void listToListMenu();
void selectListMenu();

void editMenuHandler();
SinglyLinked S_LIST_A, S_LIST_B;

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
    cout<<"12. Sort List\n";
    cout<<"13. Delete Entire List\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}
void editMenuHandler(){
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
                S_LIST_A.insertAtBeginning(valueAtBeginning);
                S_LIST_A.display();
                cout<<"\n";
                break;
            case 2:
                cout<<"Insert value at End: ";
                int valueAtEnd;
                cin>>valueAtEnd;
                cout<<"\n";
                S_LIST_A.insertAtEnd(valueAtEnd);
                S_LIST_A.display();
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
                S_LIST_A.insertAtPosition(value,position);
                S_LIST_A.display();
                }
                break;
            case 4:
                cout<<"Delete at the Beginning...\n";
                S_LIST_A.deleteAtBeginning();
                S_LIST_A.display();
                break;
            case 5:
                cout<<"Delete at the End...\n";
                S_LIST_A.deleteAtEnd();
                S_LIST_A.display();
                cout<<"\n";
                break;
            case 6:
                cout<<"Insert at a chosen position...\n";
                {
                int position;
                cin>>position;
                cout<<"\n";
                S_LIST_A.deleteAtPosition(position);
                S_LIST_A.display();
                }
                break;
            case 7:
                cout<<"Search if a value exists in the list...\n";
                {
                    int value;
                    cout<<"Enter the value to be searched: ";
                    cin>>value;
                    cout<<"\n";
                    if(S_LIST_A.search(value)){
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
                    S_LIST_A.updateNodeValue(oldV,newV);
                    S_LIST_A.display();
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
                    S_LIST_A.updateAtPosition(position,newV);
                    S_LIST_A.display();
                }
                break;
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
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}
void listToListMenu(){
    cout<<"\n--- List-to-List Operations ---\n";
    cout<<"1. Concatenate Two Lists\n";
    cout<<"2. Copy/Clone a List\n";
    cout<<"3. Merge Two Sorted Lists\n";
    cout<<"4. Compare Two Lists\n";
    cout<<"5. Intersection of Two Lists\n";
    cout<<"6. Union of Two Lists\n";
    cout<<"7. Difference of Two Lists\n";
    cout<<"8. Alternate Merge\n";
    cout<<"9. Swap Contents\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}
void selectListMenu() {
    cout<<"\n---Select Linked List---\n";
    cout<<"1. Singly Linked List\n";
    cout<<"2. Doubly Linked List\n";
    cout<<"3. Circular Linked List\n";
    cout<<"Choice: ";
}

void intermediateMenuHandler() {
    int choice;
    while (true) {
        intermediateMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Find Middle Node: Not implemented yet.\n";
                break;
            case 2:
                cout << "Remove duplicates: Not implemented yet.\n";
                break;
            case 3:
                cout << "Swap two nodes: Not implemented yet.\n";
                break;
            case 4:
                cout << "Reverse List: Not implemented yet.\n";
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

void listToListMenuHandler() {
    int choice;
    while (true) {
        listToListMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Concatenate Two Lists: Not implemented yet.\n";
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
                cout<<"Creating a new linked list...\n";
                S_LIST_A.createList(0);
                break;
            case 3:
                cout<<"Displaying a linked list...\n";
                S_LIST_A.display();
                break;
            case 4:
                editMenuHandler();
                break;
            case 5:
                intermediateMenuHandler();
                break;
            case 6:
                listToListMenuHandler();
                break;
            default:
                cout<<"Invalid choice...\n";
        }
    } while (mainChoice !=0);
    return 0;
}