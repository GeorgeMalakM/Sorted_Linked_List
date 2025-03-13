/*
* Authors:
    * Author1: Esraa Emary Abd El-Salam              ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader            ID: 20231143
    * Author3: Mariam Badr Yehia                     ID: 20230391
    * Author4: John Ayman Demian                     ID: 20230109
    * Author5: George Malak Magdy                    ID: 20231042

* Date: 15 / 3 / 2025
* Prof: Dr. Besheer

* Description:
    This project implements a **Sorted Linked List** that maintains its elements in sorted order
    using **insertion sort logic**. The list supports insertion, deletion,
    overloaded operators, and proper memory management.

* Version: V1.0
*/
// ********************************************************************************************************

#include <bits/stdc++.h>

using namespace std;

// --------------------------------------------- NODE CLASS FOR LINKED LIST.
class Node {
public:
    int data;
    Node *next;

    Node(int val);    // Constructor
};

// --------------------------------------------- SORTED LINKED LIST CLASS.
class SortedLinkedList {
    Node *head;         // Pointer to the head of the list.
public:
    SortedLinkedList();    // Constructor

    void insert(int value);     // Insert a value in the list while the list remains sorted.
    void remove(int index);     // Delete node at a given index.

    // Overloaded operators.
    friend ostream &operator<<(ostream &os, const SortedLinkedList &list);

    int operator[](int index);

    ~SortedLinkedList();    // Destructor to free the memory.
};

// --------------------------------------------- IMPLEMENTATION OF NODE CLASS.
Node::Node(int val) {
    data = val;
    next = nullptr;
}

// --------------------------------------------- IMPLEMENTATION OF SORTED LINKED LIST CLASS.
// ------------------ CONSTRUCTOR.
SortedLinkedList::SortedLinkedList() {
    head = nullptr;
}

// ------------------ INSERT FUNCTION.
void SortedLinkedList::insert(int value) {
    Node *newNode = new Node(value);
    // Case 1: Insert at the beginning or empty list
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Insert in the middle or end
    Node *curr = head;
    while (curr->next != nullptr && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

// ------------------ REMOVE FUNCTION.
void SortedLinkedList::remove(int index) {

}

// ------------------ OVERLOADED OPERATORS.
ostream &operator<<(ostream &os, const SortedLinkedList &list) {
    // George doesn't do this code.
    os << "[";
    Node *curr = list.head;
    while (curr != nullptr) {
        os << curr->data;
        if (curr->next != nullptr) os << ",";
        curr = curr->next;
    }
    os << "]";
    return os;
}

int SortedLinkedList::operator[](int index) {
    // not done yet
    try {
        if (index < 0) {
            throw out_of_range("The index cannot be negative, that will be out of bounds !!");
        }
        Node *Current = head;
        int Cur_index = 0;
        while (Current != nullptr) {
            if (Cur_index == index) {
                return Current->data;
            }
            Current = Current->next;
            Cur_index++;
        }
        throw out_of_range("Index out of bounds!");
    }
    catch (const out_of_range &e) {
        cout << "\nError: " << e.what() << endl;
        return 0;
    }
}

// ------------------ DESTRUCTOR.
SortedLinkedList::~SortedLinkedList() {

}

// --------------------------------------------- GET ELEMENT FUNCTION.
bool getElement(string &element) {
    getline(cin, element);
    if (element.empty()) {                                          // check if the input is empty.
        cout << "Invalid Input!\n";
        return false;
    } else {
        for (int i = 0; i < element.size(); ++i) {
            if (i == 0 && element[i] == '-') continue;              // check if the element is negative.
            else if (element[i] < '0' || element[i] > '9') {        // check if the element is a number.
                cout << "Invalid Input!\n";
                return false;
            }
        }
    }
    return true;
}

// --------------------------------------------- MAIN FUNCTION.
int main() {
    string choice, element;
    SortedLinkedList list;

    cout << "<------------------------------- WELCOME TO OUR LINKED LIST! -------------------------------> \n";
    while (true) {
        cout << "\nWhat do you want to do?\n1. Inserting Elements into the Sorted Linked List.\n"          // show menu.
                "2. Accessing Elements Using Index Operator.\n3. Deleting Elements from the Linked List."
                "\n4. print the list.\n5. Exit.\nEnter your choice (1-5):";
        getline(cin, choice);

        while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
            cout << "Invalid Input!\n";                                                   // check option exist in menu.
            cout << "\nWhat do you want to do?\n1. Inserting Elements into the Sorted Linked List.\n"      // show menu.
                    "2. Accessing Elements Using Index Operator.\n3. Deleting Elements from the Linked List."
                    "\n4. print the list.\n5. Exit.\nEnter your choice (1-5):";
            getline(cin, choice);
        }

        if (choice == "1") {                                          // Inserting Elements into the Sorted Linked List.
            do {
                cout << "Please enter element to insert.\n";
            } while (!getElement(element));
            list.insert(stoi(element));
            cout << "Inserted successfully!\n";
        } else if (choice == "2") {                                          // Accessing Elements Using Index Operator.
            do {
                cout << "Please enter index of element you want to access.\n";
            } while (!getElement(element));
            cout << "Element at index " << stoi(element) << " is " << list[stoi(element)] << "\n";
        } else if (choice == "3") {                                           // Deleting Elements from the Linked List.
            do {
                cout << "Please enter index of element you want to delete.\n";
            } while (!getElement(element));
            list.remove(stoi(element));
            cout << "Deleted successfully!\n";
        } else if (choice == "4") cout << "Sorted Linked List: " << list << "\n";                     // print the list.
        else if (choice == "5") break;
    }
    cout << "\nTHANKS FOR USING OUR APPLICATION :)";
}
