#include <iostream>
#include <memory>
#include "Array.hpp"
#include "StaticArray.hpp"
#include "DynamicArray.hpp"
#include "CircularArray.hpp"
#include "MultidimensionalArray.hpp"
#include "JaggedArray.hpp"

using namespace std;

// Function declarations
void showMenu();
void editMenu();
void intermediateMenu();
void arrayToArrayMenu();
void selectArrayMenu();
void editMenuHandler();
void selectMenuHandler();
void intermediateMenuHandler();
void arrayToArrayMenuHandler();

// Global variable to hold current array
Array* currentArray = NULL;

void showMenu() {
    cout << "\n--- Array Operations Menu ---\n";
    cout << "1. Create a new array\n";
    cout << "2. Select/switch current array\n";
    cout << "3. Display current array\n";
    cout << "4. Edit current array\n";
    cout << "5. Perform intermediate operations\n";
    cout << "6. Array-to-array operations\n";
    cout << "7. Delete current array\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

void selectArrayMenu() {
    cout << "\n---Select Array Type---\n";
    cout << "1. Static Array\n";
    cout << "2. Dynamic Array\n";
    cout << "3. Circular Array\n";
    cout << "4. Multidimensional Array\n";
    cout << "5. Jagged Array\n";
    cout << "Choice: ";
}

void selectArrayHandler() {
    int choice;
    selectArrayMenu();
    cin >> choice;
    
    if (currentArray) {
        currentArray->clear();
        delete currentArray;
        currentArray = NULL;
    }
    
    switch(choice) {
        case 1:
            currentArray = new StaticArray();
            cout << "Static Array created successfully!\n";
            break;
        case 2:
            currentArray = new DynamicArray();
            cout << "Dynamic Array created successfully!\n";
            break;
        case 3:
            currentArray = new CircularArray();
            cout << "Circular Array created successfully!\n";
            break;
        case 4:
            currentArray = new MultidimensionalArray();
            cout << "Multidimensional Array created successfully!\n";
            break;
        case 5:
            currentArray = new JaggedArray();
            cout << "Jagged Array created successfully!\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void editMenu() {
    cout << "\n---Edit Array Menu---\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert at position\n";
    cout << "4. Delete at beginning\n";
    cout << "5. Delete at end\n";
    cout << "6. Delete at position\n";
    cout << "7. Update at position\n";
    cout << "8. Update by value\n";
    cout << "9. Create array with size\n";
    cout << "0. Back to main menu\n";
    cout << "Choice: ";
}

void editMenuHandler() {
    int choice, value, position, size;
    editMenu();
    cin >> choice;
    
    if (!currentArray) {
        cout << "No array selected! Please create or select an array first.\n";
        return;
    }
    
    switch(choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            currentArray->insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            currentArray->insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            currentArray->insertAtPosition(value, position);
            break;
        case 4:
            currentArray->deleteAtBeginning();
            break;
        case 5:
            currentArray->deleteAtEnd();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            currentArray->deleteAtPosition(position);
            break;
        case 7:
            cout << "Enter position to update: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> value;
            currentArray->updateAtPosition(position, value);
            break;
        case 8:
            cout << "Enter old value: ";
            cin >> value;
            cout << "Enter new value: ";
            cin >> position;
            currentArray->updateValue(value, position);
            break;
        case 9:
            cout << "Enter array size: ";
            cin >> size;
            currentArray->createArray(size);
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void intermediateMenu() {
    cout << "\n---Intermediate Operations Menu---\n";
    cout << "1. Search element\n";
    cout << "2. Reverse array\n";
    cout << "3. Find middle element\n";
    cout << "4. Remove duplicates\n";
    cout << "5. Swap elements\n";
    cout << "6. Sort array\n";
    cout << "7. Get array size\n";
    cout << "8. Check if empty\n";
    cout << "9. Get element at position\n";
    cout << "10. Clear array\n";
    cout << "0. Back to main menu\n";
    cout << "Choice: ";
}

void intermediateMenuHandler() {
    int choice, value, pos1, pos2, position;
    intermediateMenu();
    cin >> choice;
    
    if (!currentArray) {
        cout << "No array selected! Please create or select an array first.\n";
        return;
    }
    
    switch(choice) {
        case 1:
            cout << "Enter value to search: ";
            cin >> value;
            if (currentArray->search(value)) {
                cout << "Element found!\n";
            } else {
                cout << "Element not found!\n";
            }
            break;
        case 2:
            currentArray->reverse();
            cout << "Array reversed!\n";
            break;
        case 3:
            cout << "Middle element: " << currentArray->findMiddle() << "\n";
            break;
        case 4:
            currentArray->removeDuplicates();
            cout << "Duplicates removed!\n";
            break;
        case 5:
            cout << "Enter first position: ";
            cin >> pos1;
            cout << "Enter second position: ";
            cin >> pos2;
            currentArray->swapElements(pos1, pos2);
            break;
        case 6:
            currentArray->sort();
            cout << "Array sorted!\n";
            break;
        case 7:
            cout << "Array size: " << currentArray->getSize() << "\n";
            break;
        case 8:
            if (currentArray->isEmpty()) {
                cout << "Array is empty!\n";
            } else {
                cout << "Array is not empty!\n";
            }
            break;
        case 9:
            cout << "Enter position: ";
            cin >> position;
            cout << "Element at position " << position << ": " << currentArray->getElementAt(position) << "\n";
            break;
        case 10:
            currentArray->clear();
            cout << "Array cleared!\n";
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void arrayToArrayMenu() {
    cout << "\n---Array-to-Array Operations Menu---\n";
    cout << "1. Clone array\n";
    cout << "2. Compare arrays\n";
    cout << "3. Merge sorted arrays\n";
    cout << "4. Concatenate arrays\n";
    cout << "5. Find intersection\n";
    cout << "6. Find union\n";
    cout << "7. Find difference\n";
    cout << "8. Alternate merge\n";
    cout << "9. Swap contents\n";
    cout << "0. Back to main menu\n";
    cout << "Choice: ";
}

void arrayToArrayMenuHandler() {
    int choice;
    arrayToArrayMenu();
    cin >> choice;
    
    if (!currentArray) {
        cout << "No array selected! Please create or select an array first.\n";
        return;
    }
    
    // For demonstration, we'll create a temporary second array
    // In a real implementation, you might want to manage multiple arrays
    Array* tempArray = new DynamicArray();
    
    switch(choice) {
        case 1: {
            Array* cloned = currentArray->clone();
            if (cloned) {
                cout << "Array cloned successfully!\n";
                cloned->display();
                delete cloned;
            }
            break;
        }
        case 2:
            if (currentArray->compare(*tempArray)) {
                cout << "Arrays are equal!\n";
            } else {
                cout << "Arrays are not equal!\n";
            }
            break;
        case 3: {
            Array* merged = currentArray->mergeSorted(*tempArray);
            if (merged) {
                cout << "Arrays merged successfully!\n";
                merged->display();
                delete merged;
            }
            break;
        }
        case 4:
            currentArray->concatenate(*tempArray);
            cout << "Arrays concatenated!\n";
            break;
        case 5: {
            Array* intersection = currentArray->intersection(*tempArray);
            if (intersection) {
                cout << "Intersection found!\n";
                intersection->display();
                delete intersection;
            }
            break;
        }
        case 6: {
            Array* unionArray = currentArray->unionWith(*tempArray);
            if (unionArray) {
                cout << "Union created!\n";
                unionArray->display();
                delete unionArray;
            }
            break;
        }
        case 7: {
            Array* difference = currentArray->difference(*tempArray);
            if (difference) {
                cout << "Difference found!\n";
                difference->display();
                delete difference;
            }
            break;
        }
        case 8: {
            Array* alternate = currentArray->alternateMerge(*tempArray);
            if (alternate) {
                cout << "Alternate merge created!\n";
                alternate->display();
                delete alternate;
            }
            break;
        }
        case 9:
            currentArray->swapContents(*tempArray);
            cout << "Contents swapped!\n";
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
    
    delete tempArray;
}

int main() {
    int choice;
    
    cout << "Welcome to Array Data Structure Operations!\n";
    
    do {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                selectArrayHandler();
                break;
            case 2:
                selectArrayHandler();
                break;
            case 3:
                if (currentArray) {
                    cout << "Current array: ";
                    currentArray->display();
                    cout << "\n";
                } else {
                    cout << "No array selected! Please create or select an array first.\n";
                }
                break;
            case 4:
                editMenuHandler();
                break;
            case 5:
                intermediateMenuHandler();
                break;
            case 6:
                arrayToArrayMenuHandler();
                break;
            case 7:
                if (currentArray) {
                    currentArray->clear();
                    delete currentArray;
                    currentArray = NULL;
                    cout << "Array deleted successfully!\n";
                } else {
                    cout << "No array to delete!\n";
                }
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while(choice != 0);
    
    // Cleanup
    if (currentArray) {
        currentArray->clear();
        delete currentArray;
    }
    
    return 0;
}
