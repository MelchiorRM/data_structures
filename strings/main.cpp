#include <iostream>
#include <memory>
#include <cstddef>
#include <cstdlib>
#include "String.hpp"
#include "StaticString.hpp"
#include "DynamicString.hpp"
#include "StringBuffer.hpp"
#include "StringBuilder.hpp"

using namespace std;

void showMenu();
void editMenu();
void intermediateMenu();
void stringToStringMenu();
void selectStringMenu();
void editMenuHandler();
void selectMenuHandler();
void intermediateMenuHandler();
void stringToStringMenuHandler();
String* currentString = NULL;

void showMenu(){
    cout<<"\n--- String Operations Menu ---\n";
    cout<<"1. Create a new string\n";
    cout<<"2. Select/switch current string\n";
    cout<<"3. Display current string\n";
    cout<<"4. Edit current string\n";
    cout<<"5. Perform intermediate operations\n";
    cout<<"6. String-to-string operations\n";
    cout<<"7. Delete a string\n";
    cout<<"0. Exit\n";
    cout<<"Choice: ";
}

void selectStringMenu() {
    cout<<"\n---Select String Type---\n";
    cout<<"1. Static String (Fixed size)\n";
    cout<<"2. Dynamic String (Resizable)\n";
    cout<<"3. String Buffer (Thread-safe)\n";
    cout<<"4. String Builder (Optimized for concatenation)\n";
    cout<<"Choice: ";
}

void selectStringHandler() {
    int choice;
    selectStringMenu();
    cin >> choice;
    if (currentString) {
        currentString->free();
        delete currentString;
        currentString = NULL;
    }
    switch(choice) {
        case 1:
            currentString = new StaticString();
            cout << "Static String selected.\n";
            break;
        case 2:
            currentString = new DynamicString();
            cout << "Dynamic String selected.\n";
            break;
        case 3:
            currentString = new StringBuffer();
            cout << "String Buffer selected.\n";
            break;
        case 4:
            currentString = new StringBuilder();
            cout << "String Builder selected.\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }
}

void editMenu(){
    cout<<"\n---Edit string---\n";
    cout<<"1. Create string from C-string\n";
    cout<<"2. Create string from std::string\n";
    cout<<"3. Create string of specific size\n";
    cout<<"4. Append character\n";
    cout<<"5. Prepend character\n";
    cout<<"6. Insert character at position\n";
    cout<<"7. Delete character at position\n";
    cout<<"8. Append string\n";
    cout<<"9. Prepend string\n";
    cout<<"10. Insert string at position\n";
    cout<<"11. Delete substring\n";
    cout<<"12. Replace substring\n";
    cout<<"13. Set character at position\n";
    cout<<"14. Get character at position\n";
    cout<<"15. Clear string\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}

void editMenuHandler(){
    if (!currentString) {
        cout << "No string selected. Please create or select a string first.\n";
        return;
    }
    int editChoice;
    while(true) {
        editMenu();
        cin>>editChoice;
        switch(editChoice){
            case 1: {
                cout<<"Enter C-string: ";
                string input;
                cin.ignore();
                getline(cin, input);
                currentString->createString(input.c_str());
                cout<<"\nString created: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 2: {
                cout<<"Enter std::string: ";
                string input;
                cin.ignore();
                getline(cin, input);
                currentString->createString(input);
                cout<<"\nString created: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 3: {
                cout<<"Enter size: ";
                int size;
                cin>>size;
                currentString->createString(size);
                cout<<"\nString of size " << size << " created: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 4: {
                cout<<"Enter character to append: ";
                char ch;
                cin>>ch;
                currentString->appendChar(ch);
                cout<<"\nCharacter appended. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 5: {
                cout<<"Enter character to prepend: ";
                char ch;
                cin>>ch;
                currentString->prependChar(ch);
                cout<<"\nCharacter prepended. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 6: {
                cout<<"Enter position and character: ";
                int pos;
                char ch;
                cin>>pos>>ch;
                currentString->insertCharAt(pos, ch);
                cout<<"\nCharacter inserted. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 7: {
                cout<<"Enter position to delete: ";
                int pos;
                cin>>pos;
                currentString->deleteCharAt(pos);
                cout<<"\nCharacter deleted. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 8: {
                cout<<"Enter string to append: ";
                string input;
                cin.ignore();
                getline(cin, input);
                currentString->append(input);
                cout<<"\nString appended. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 9: {
                cout<<"Enter string to prepend: ";
                string input;
                cin.ignore();
                getline(cin, input);
                currentString->prepend(input);
                cout<<"\nString prepended. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 10: {
                cout<<"Enter position and string: ";
                int pos;
                string input;
                cin>>pos;
                cin.ignore();
                getline(cin, input);
                currentString->insertAt(pos, input);
                cout<<"\nString inserted. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 11: {
                cout<<"Enter position and count to delete: ";
                int pos, count;
                cin>>pos>>count;
                currentString->deleteAt(pos, count);
                cout<<"\nSubstring deleted. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 12: {
                cout<<"Enter old string and new string: ";
                string oldStr, newStr;
                cin.ignore();
                getline(cin, oldStr);
                getline(cin, newStr);
                currentString->replace(oldStr, newStr);
                cout<<"\nString replaced. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 13: {
                cout<<"Enter position and character: ";
                int pos;
                char ch;
                cin>>pos>>ch;
                currentString->setCharAt(pos, ch);
                cout<<"\nCharacter set. Current string: ";
                currentString->display();
                cout<<"\n";
                break;
            }
            case 14: {
                cout<<"Enter position: ";
                int pos;
                cin>>pos;
                char ch = currentString->getCharAt(pos);
                cout<<"\nCharacter at position " << pos << ": " << ch << "\n";
                break;
            }
            case 15: {
                currentString->clear();
                cout<<"\nString cleared.\n";
                break;
            }
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
    cout<<"1. Find substring\n";
    cout<<"2. Find character\n";
    cout<<"3. Check if starts with\n";
    cout<<"4. Check if ends with\n";
    cout<<"5. Check if contains\n";
    cout<<"6. Compare with string\n";
    cout<<"7. Convert to uppercase\n";
    cout<<"8. Convert to lowercase\n";
    cout<<"9. Reverse string\n";
    cout<<"10. Trim whitespace\n";
    cout<<"11. Remove whitespace\n";
    cout<<"12. Count occurrences\n";
    cout<<"13. Count words\n";
    cout<<"14. Count lines\n";
    cout<<"15. Check if numeric\n";
    cout<<"16. Check if alphabetic\n";
    cout<<"17. Check if alphanumeric\n";
    cout<<"18. Get substring\n";
    cout<<"19. Get string length\n";
    cout<<"20. Get string capacity\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}

void intermediateMenuHandler() {
    if (!currentString) {
        cout << "No string selected. Please create or select a string first.\n";
        return;
    }
    
    int choice;
    while (true) {
        intermediateMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter substring to find: ";
                string substr;
                cin.ignore();
                getline(cin, substr);
                int pos = currentString->find(substr);
                if (pos != -1) {
                    cout << "Substring found at position: " << pos << "\n";
                } else {
                    cout << "Substring not found.\n";
                }
                break;
            }
            case 2: {
                cout << "Enter character to find: ";
                char ch;
                cin >> ch;
                int pos = currentString->findChar(ch);
                if (pos != -1) {
                    cout << "Character found at position: " << pos << "\n";
                } else {
                    cout << "Character not found.\n";
                }
                break;
            }
            case 3: {
                cout << "Enter prefix to check: ";
                string prefix;
                cin.ignore();
                getline(cin, prefix);
                if (currentString->startsWith(prefix)) {
                    cout << "String starts with the prefix.\n";
                } else {
                    cout << "String does not start with the prefix.\n";
                }
                break;
            }
            case 4: {
                cout << "Enter suffix to check: ";
                string suffix;
                cin.ignore();
                getline(cin, suffix);
                if (currentString->endsWith(suffix)) {
                    cout << "String ends with the suffix.\n";
                } else {
                    cout << "String does not end with the suffix.\n";
                }
                break;
            }
            case 5: {
                cout << "Enter substring to check: ";
                string substr;
                cin.ignore();
                getline(cin, substr);
                if (currentString->contains(substr)) {
                    cout << "String contains the substring.\n";
                } else {
                    cout << "String does not contain the substring.\n";
                }
                break;
            }
            case 6: {
                cout << "Enter string to compare: ";
                string str;
                cin.ignore();
                getline(cin, str);
                int result = currentString->compare(str);
                if (result == 0) {
                    cout << "Strings are equal.\n";
                } else if (result < 0) {
                    cout << "Current string is less than the given string.\n";
                } else {
                    cout << "Current string is greater than the given string.\n";
                }
                break;
            }
            case 7: {
                currentString->toUpperCase();
                cout << "String converted to uppercase: ";
                currentString->display();
                cout << "\n";
                break;
            }
            case 8: {
                currentString->toLowerCase();
                cout << "String converted to lowercase: ";
                currentString->display();
                cout << "\n";
                break;
            }
            case 9: {
                currentString->reverse();
                cout << "String reversed: ";
                currentString->display();
                cout << "\n";
                break;
            }
            case 10: {
                currentString->trim();
                cout << "String trimmed: ";
                currentString->display();
                cout << "\n";
                break;
            }
            case 11: {
                currentString->removeWhitespace();
                cout << "Whitespace removed: ";
                currentString->display();
                cout << "\n";
                break;
            }
            case 12: {
                cout << "Enter substring to count: ";
                string substr;
                cin.ignore();
                getline(cin, substr);
                int count = currentString->countOccurrences(substr);
                cout << "Occurrences: " << count << "\n";
                break;
            }
            case 13: {
                int words = currentString->countWords();
                cout << "Word count: " << words << "\n";
                break;
            }
            case 14: {
                int lines = currentString->countLines();
                cout << "Line count: " << lines << "\n";
                break;
            }
            case 15: {
                if (currentString->isNumeric()) {
                    cout << "String is numeric.\n";
                } else {
                    cout << "String is not numeric.\n";
                }
                break;
            }
            case 16: {
                if (currentString->isAlpha()) {
                    cout << "String is alphabetic.\n";
                } else {
                    cout << "String is not alphabetic.\n";
                }
                break;
            }
            case 17: {
                if (currentString->isAlphaNumeric()) {
                    cout << "String is alphanumeric.\n";
                } else {
                    cout << "String is not alphanumeric.\n";
                }
                break;
            }
            case 18: {
                cout << "Enter start and end positions: ";
                int start, end;
                cin >> start >> end;
                String* sub = currentString->substring(start, end);
                cout << "Substring: ";
                sub->display();
                cout << "\n";
                delete sub;
                break;
            }
            case 19: {
                cout << "String length: " << currentString->getLength() << "\n";
                break;
            }
            case 20: {
                cout << "String capacity: " << currentString->getCapacity() << "\n";
                break;
            }
            case 0:
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

void stringToStringMenu(){
    cout<<"\n--- String-to-String Operations ---\n";
    cout<<"1. Concatenate Two Strings\n";
    cout<<"2. Copy/Clone a String\n";
    cout<<"3. Compare Two Strings\n";
    cout<<"4. Swap String Contents\n";
    cout<<"5. Merge Strings\n";
    cout<<"6. Split String\n";
    cout<<"7. Join Strings\n";
    cout<<"0. Back to Main Menu\n";
    cout<<"Choice: ";
}

void stringToStringMenuHandler() {
    int choice;
    while (true) {
        stringToStringMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Concatenate Two Strings: Not implemented yet...\n";
                break;
            case 2:
                if (currentString) {
                    String* cloned = currentString->clone();
                    cout << "String cloned: ";
                    cloned->display();
                    cout << "\n";
                    delete cloned;
                } else {
                    cout << "No string selected.\n";
                }
                break;
            case 3:
                cout << "Compare Two Strings: Not implemented yet.\n";
                break;
            case 4:
                cout << "Swap String Contents: Not implemented yet.\n";
                break;
            case 5:
                cout << "Merge Strings: Not implemented yet.\n";
                break;
            case 6:
                cout << "Split String: Not implemented yet.\n";
                break;
            case 7:
                cout << "Join Strings: Not implemented yet.\n";
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
                selectStringHandler();
                if (currentString) {
                    currentString->createString(0);
                }
                break;
            case 2:
                selectStringHandler();
                break;
            case 3:
                if (currentString) {
                    cout<<"Displaying the current string...\n";
                    currentString->display();
                    cout << "\n";
                } else {
                    cout<<"No string selected.\n";
                }
                break;
            case 4:
                editMenuHandler();
                break;
            case 5:
                intermediateMenuHandler();
                break;
            case 6:
                stringToStringMenuHandler();
                break;
            case 7:
                if (currentString) {
                    currentString->free();
                    delete currentString;
                    currentString = NULL;
                    cout << "Current string deleted.\n";
                } else {
                    cout << "No string to delete.\n";
                }
                break;
            default:
                cout<<"Invalid choice...\n";
        }
    } while (mainChoice !=0);
    if (currentString) {
        currentString->free();
        delete currentString;
    }
    return 0;
}
