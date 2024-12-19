#include <iostream>
#include <string>
#include <cstdlib> // For malloc/free

using namespace std;

class Contact {
public:
    string firstName, lastName, phoneNumber;
    Contact* next;

    Contact() : firstName(""), lastName(""), phoneNumber(""), next(nullptr) {}
};

class PhoneBook {
private:
    Contact* head;

public:
    PhoneBook() : head(nullptr) {}

    void menu() {
        int choice;
        while (true) {
            cout << "\nPHONEBOOK\n";
            cout << "------------------\n";
            cout << "1. Add\n";
            cout << "2. Search\n";
            cout << "3. Modify\n";
            cout << "4. Delete\n";
            cout << "5. Display\n";
            cout << "6. EXIT\n";
            cout << "Enter your choice (1-6): ";
            cin >> choice;

            switch (choice) {
                case 1: addDetails(); break;
                case 2: searchDetails(); break;
                case 3: modifyDetails(); break;
                case 4: deleteDetails(); break;
                case 5: display(); break;
                case 6: exit(0); break;
                default: cout << "Enter valid input only!\n";
            }
        }
    }

    void addDetails() {
        Contact* newContact = new Contact();

        cout << "First name: ";
        cin >> newContact->firstName;
        cout << "Last name: ";
        cin >> newContact->lastName;
        cout << "Telephone No.: ";
        cin >> newContact->phoneNumber;
        newContact->next = nullptr;

        if (!head) {
            head = newContact;
        } else {
            Contact *ptr = head, *prev = nullptr;
            while (ptr && newContact->firstName > ptr->firstName) {
                prev = ptr;
                ptr = ptr->next;
            }

            if (!prev) {
                newContact->next = head;
                head = newContact;
            } else if (!ptr) {
                prev->next = newContact;
            } else {
                newContact->next = ptr;
                prev->next = newContact;
            }
        }

        cout << "Contact added successfully!\n";
    }

    void searchDetails() {
        if (!head) {
            cout << "\nPhonebook is Empty....\n";
            return;
        }

        string firstName;
        cout << "First Name to Find: ";
        cin >> firstName;

        Contact* ptr = head;
        while (ptr && ptr->firstName != firstName) {
            ptr = ptr->next;
        }

        if (ptr) {
            cout << "First Name: " << ptr->firstName << "\n";
            cout << "Last Name: " << ptr->lastName << "\n";
            cout << "Phone Number: " << ptr->phoneNumber << "\n";
        } else {
            cout << "No such record Found .......\n";
        }
    }

    void modifyDetails() {
        if (!head) {
            cout << "\nPhonebook is Empty....\n";
            return;
        }

        string firstName;
        cout << "First Name to Edit: ";
        cin >> firstName;

        Contact* ptr = head;
        while (ptr && ptr->firstName != firstName) {
            ptr = ptr->next;
        }

        if (ptr) {
            cout << "Editing Contact...\n";
            cout << "First Name (" << ptr->firstName << "): ";
            cin >> ptr->firstName;
            cout << "Last Name (" << ptr->lastName << "): ";
            cin >> ptr->lastName;
            cout << "Phone Number (" << ptr->phoneNumber << "): ";
            cin >> ptr->phoneNumber;
            cout << "Contact modified successfully!\n";
        } else {
            cout << "No such record Found .......\n";
        }
    }

    void deleteDetails() {
        if (!head) {
            cout << "\nPhonebook is Empty....\n";
            return;
        }

        string firstName;
        cout << "First Name to Delete: ";
        cin >> firstName;

        Contact *ptr = head, *prev = nullptr;

        while (ptr && ptr->firstName != firstName) {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr) {
            if (!prev) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            delete ptr;
            cout << "The record has been deleted successfully.\n";
        } else {
            cout << "No such record Found .......\n";
        }
    }

    void display() {
        if (!head) {
            cout << "\nTelephone Directory is Empty....\n";
            return;
        }

        cout << "\t\t------------------------------\n";
        Contact* ptr = head;
        while (ptr) {
            cout << "\t\tFirst name: " << ptr->firstName << "\n";
            cout << "\t\tLast name: " << ptr->lastName << "\n";
            cout << "\t\tTelephone No.: " << ptr->phoneNumber << "\n";
            cout << "\t\t------------------------------\n";
            ptr = ptr->next;
        }
    }

    ~PhoneBook() {
        while (head) {
            Contact* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    phoneBook.menu();
    return 0;
}
