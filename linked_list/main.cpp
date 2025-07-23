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
    cout<<"8. Update Node Value\n";
    cout<<"9. Count Nodes\n";
    cout<<"10. Reverse List\n";
    cout<<"11. Sort List\n";
    cout<<"12. Delete Entire List\n";
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
            default:
                cout<<"Invalid choice...\n";
                
        }
    }
}
void intermediateMenu(){
    cout<<"\n---Intermediate operations---\n";
    cout<<"1. Find Middle Node\n";
    cout<<"2. Remove duplicates\n";
    cout<<"3. Swap two nodes\n";
    cout<<"4. Find Nth from the end\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}
void listToListMenu(){
    cout<<"\n--- List-to-List Operations ---\n";
    cout<<"0. Back to Main Menu\n";
}
void selectListMenu() {
    cout<<"\n---Select Linked List---\n";
    cout<<"1. Singly Linked List\n";
    cout<<"2. Doubly Linked List\n";
    cout<<"3. Circular Linked List\n";
    cout<<"Choice: ";
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
            default:
                cout<<"Invalid choice...\n";
        }
    } while (mainChoice !=0);
    return 0;
}