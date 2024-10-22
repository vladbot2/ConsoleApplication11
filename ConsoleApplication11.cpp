#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
    string fullName;
    string mobilePhone;

public:
    Contact() {}

    Contact(string name, string mobilePhone) {
        fullName = name;
        this->mobilePhone = mobilePhone;
    }

    string getFullName() {
        return fullName;
    }

    void showContact() {
        cout << "Full Name: " << fullName << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
    }
};

class PhoneBook {
    vector<Contact> contacts;

public:
    void addContact(Contact contact) {
        contacts.push_back(contact);
    }

    void searchContact(string fullName) {
        for (auto& contact : contacts) {
            if (contact.getFullName() == fullName) {
                contact.showContact();
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    void showAllContacts() {
        if (contacts.empty()) {
            cout << "Phone book is empty." << endl;
        }
        else {
            for (auto& contact : contacts) {
                contact.showContact();
                cout << "---------------------" << endl;
            }
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    string name, mobilePhone;

    do {
        cout << "Phone Book Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Show All Contacts" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter full name: ";
            getline(cin, name);
            cout << "Enter mobile phone: ";
            getline(cin, mobilePhone);
            phoneBook.addContact(Contact(name, mobilePhone));
            break;
        case 2:
            cout << "Enter full name to search: ";
            getline(cin, name);
            phoneBook.searchContact(name);
            break;
        case 3:
            phoneBook.showAllContacts();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}
