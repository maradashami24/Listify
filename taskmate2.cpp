#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

double performOperation(double operand1, double operand2, char op) {
    if (op == '+') return operand1 + operand2;
    if (op == '-') return operand1 - operand2;
    if (op == '*') return operand1 * operand2;
    if (op == '/') {
        if (operand2 == 0) {
            cout << "Division by zero error!" << endl;
            exit(EXIT_FAILURE);
        }
        return operand1 / operand2;
    }
    cout << "Invalid operator!" << endl;
    exit(EXIT_FAILURE);
}

double evaluatePostfix(string exp) {
    stack<double> s;
    istringstream iss(exp);
    string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            s.push(stod(token));  
        } else {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            s.push(performOperation(a, b, token[0]));
        }
    }
    return s.top();
}

void calculator(){
    string expression;
    cout << "Enter postfix expression (use spaces between tokens): ";
    getline(cin, expression);
    cout << "Result: " << evaluatePostfix(expression) << endl;
}

struct Task{
    string description;
    int complete;
    struct Task* next;
};

Task* createTask(string desc){
    Task* newtask = new Task;
    newtask->description = desc;
    newtask->complete = 0;
    newtask->next = NULL;
    return newtask;
}

void addTask(Task* &head, string desc){
    Task* newTask = createTask(desc);
    newTask->next = head;
    head = newTask;
    cout << "New task added successfully" << endl;
}

void DisplayTasks(Task* head){
    if(head == NULL){
        cout << "No tasks to display" << endl;
        return;
    }
    cout << "\nYOUR TASKS:" << endl;
    Task* temp = head;
    while(temp != NULL){
        if(temp->complete){
            cout << "[X] " << temp->description << endl;
        }
        else{
            cout << "[ ] " << temp->description << endl;
        }
        temp = temp->next;
    }
}

void markComplete(Task* head, string desc){
    Task* temp = head;
    while(temp != NULL){
        if(temp->description == desc){
            temp->complete = 1;
            cout << "Marked complete" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found" << endl;
}

void deletelist(Task* head){
    while(head != NULL){
        Task* temp = head;
        head = head->next;
        delete temp;
    }
}

void todoList(){
    Task* todoList = NULL;
    int choice;
    do{
        cout << "\nTO-DO LIST MENU" << endl;
        cout << "\n1. Add Task\n2. Display Task\n3. Mark as Complete\n4. Quit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();  

        string d;
        switch(choice){
            case 1:
                cout << "Enter task Description: ";
                getline(cin, d);  
                addTask(todoList, d);
                break;
            case 2:
                DisplayTasks(todoList);
                break;
            case 3:
                cout << "Enter task description to be marked as completed: ";
                getline(cin, d);  // Capture task description with spaces
                markComplete(todoList, d);
                break;
            case 4:
                cout << "Exiting To-Do List" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while(choice != 4);
    deletelist(todoList);
}

struct Contact {
    string name;
    vector<string> phoneNumbers; // Store multiple phone numbers
    struct Contact* next;
    struct Contact* prev;
};

Contact* CreateContact(string name) {
    Contact* newContact = new Contact;
    newContact->name = name;
    newContact->next = NULL;
    newContact->prev = NULL;
    return newContact;
}

// Function to add a phone number to an existing contact
void addPhoneNumber(Contact* contact, string phone) {
    contact->phoneNumbers.push_back(phone);
}

// Function to add a new contact at the tail
void addNewContact(Contact*& head, string name, string phone) {
    Contact* newContact = CreateContact(name);
    addPhoneNumber(newContact, phone);  // Add the first phone number

    if (head == NULL) {
        head = newContact; // If the list is empty, set the new contact as head
    } else {
        // Traverse to the end of the list (tail)
        Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
        newContact->prev = temp;
    }

    cout << "Contact added" << endl;
}

// Function to find an existing contact by name
Contact* findContact(Contact* head, string name) {
    Contact* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Contact not found
}

// Function to add a phone number to an existing contact
void addPhoneNumberToExistingContact(Contact*& head, string name, string phone) {
    Contact* contact = findContact(head, name);
    if (contact != NULL) {
        addPhoneNumber(contact, phone);
        cout << "Phone number added to existing contact" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
}

// Function to display contacts in original order
void displayContactsInOriginalOrder(Contact* head) {
    if (head == NULL) {
        cout << "Contact List Empty" << endl;
        return;
    }

    Contact* temp = head;
    cout << "\nContact List (Original Order):" << endl;
    while (temp != NULL) {
        cout << temp->name << ": ";
        for (const auto& phone : temp->phoneNumbers) {
            cout << phone << " "; // Display all phone numbers
        }
        cout << endl;
        temp = temp->next;
    }
}

// Function to display contacts in most recently added first
void displayContactsMostRecentFirst(Contact* head) {
    if (head == NULL) {
        cout << "Contact List Empty" << endl;
        return;
    }

    // Traverse to the tail (most recent)
    Contact* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "\nContact List (Most Recently Added First):" << endl;
    while (temp != NULL) {
        cout << temp->name << ": ";
        for (const auto& phone : temp->phoneNumbers) {
            cout << phone << " "; // Display all phone numbers
        }
        cout << endl;
        temp = temp->prev; // Move towards the head
    }
}

void searchContact(Contact* head, string name) {
    Contact* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Contact Found" << endl;
            cout << temp->name << ": ";
            for (const auto& phone : temp->phoneNumbers) {
                cout << phone << " "; // Display all phone numbers
            }
            return;
        }
        temp = temp->next;
    }
    cout << "\nContact not found" << endl;
}

void freeList(Contact*& head) {
    Contact* temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void ContactList() {
    Contact* contactList = NULL;
    int choice;
    string name, phone;
    do {
        cout << "\n=====================================================\n";
        cout << "Contact List Menu\n";
        cout << "=====================================================\n";
        cout << "1. Add New Contact\n";
        cout << "2. Add Phone Number to Existing Contact\n";
        cout << "3. Display Contacts\n";
        cout << "4. Search Contact\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // To clear the newline character left in the input buffer after reading choice

        switch (choice) {
            case 1:
                cout << "\n=====================================================\n";
                int addChoice;
                cout << "1. Create New Contact\n";
                cout << "2. Add Phone Number to Existing Contact\n";
                cout << "Enter your choice: ";
                cin >> addChoice;
                cin.ignore(); // Clear the buffer for further input

                if (addChoice == 1) {
                    cout << "Enter contact name: ";
                    getline(cin, name);
                    cout << "Enter phone number: ";
                    getline(cin, phone);
                    addNewContact(contactList, name, phone);
                } else if (addChoice == 2) {
                    cout << "Enter contact name to add phone number: ";
                    getline(cin, name);
                    cout << "Enter phone number to add: ";
                    getline(cin, phone);
                    addPhoneNumberToExistingContact(contactList, name, phone);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            case 2:
                cout << "\n=====================================================\n";
                cout << "Enter contact name to add phone number: ";
                getline(cin, name);
                cout << "Enter phone number to add: ";
                getline(cin, phone);
                addPhoneNumberToExistingContact(contactList, name, phone);
                break;
            case 3:
                cout << "\n=====================================================\n";
                int displayChoice;
                cout << "1. Display in Original Order\n";
                cout << "2. Display Most Recently Added First\n";
                cout << "Enter your choice: ";
                cin >> displayChoice;

                if (displayChoice == 1) {
                    displayContactsInOriginalOrder(contactList);
                } else if (displayChoice == 2) {
                    displayContactsMostRecentFirst(contactList);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            case 4:
                cout << "\n=====================================================\n";
                cout << "Enter contact name to search:";
                getline(cin, name);
                searchContact(contactList, name);
                break;
            case 5:
                cout << "\n=====================================================\n";
                cout << "Quitting the contact list app.\n";
                break;
            default:
                cout << "\n=====================================================\n";
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    freeList(contactList);
}


int main() {
    int choice = 0;
    do {
        cout << "\n=====================================================\n";
        cout << "Task Mate\n";
        cout << "=====================================================\n";
        cout << "1. Calculator\n2. Todo List\n3. Contact List\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To clear the newline character

        switch(choice) {
            case 1:
                calculator();
                break;
            case 2:
                todoList();
                break;
            case 3:
                ContactList();
                break;
            case 4:
                cout << "Exited!" << endl;
                break;
            default:
                cout << "Enter valid input!" << endl;
        }
    } while(choice != 4);
    return 0;
}
