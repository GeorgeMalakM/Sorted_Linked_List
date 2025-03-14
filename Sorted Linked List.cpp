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
    This project implements a Sorted Linked List that maintains its elements in sorted order
    using insertion sort logic. The list supports insertion, deletion,
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
    Node(int val);              // Constructor.
};

// --------------------------------------------- SORTED LINKED LIST CLASS.
class SortedLinkedList {
    Node *head;                         // Pointer to the head of the list.
public:
    SortedLinkedList();                 // Constructor.
    ~SortedLinkedList();                // Destructor to free the memory.

    void insert(int value);             // Insert a value in the list while the list remains sorted.
    void remove(int index);             // Delete node at a given index.

    friend ostream &operator<<(ostream &os, const SortedLinkedList &list);           // Overloaded operators.
    int operator[](int index);
};

// --------------------------------------------- IMPLEMENTATION OF NODE CLASS.
Node::Node(const int val) {
    data = val;
    next = nullptr;
}

// --------------------------------------------- IMPLEMENTATION OF SORTED LINKED LIST CLASS.
// ------------------ CONSTRUCTOR.
SortedLinkedList::SortedLinkedList() {
    head = nullptr;
}

// ------------------ INSERT FUNCTION.
void SortedLinkedList::insert(const int value) {
    const auto newNode = new Node(value);

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
    bool found = false;

    // Case 1: The list is empty.
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }

    // Case 2: Out of range.
    while (index < 0) {
        cout << "Out of range" << endl;
        cout << "Please, enter a valid index: " << endl;
        cin >> index;
    }

    // Case 3: Remove the first element.
    if (index == 0) {
        const Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 4: Remove from the middle or end.
    while (!found) {
        Node *curr = head;
        Node *prev = nullptr;
        int count = 0;

        // Traverse to the correct index.
        while (curr != nullptr && count < index) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // If index out of range.
        if (!curr) {
            cout << "Index out of range" << endl;
            cout << "Please, enter a valid index: " << endl;
            cin >> index;
            continue;
        }

        // Remove the node at the index.
        prev->next = curr->next;
        delete curr;
        found = true;
    }
}

// ------------------ OVERLOADED OPERATORS.
ostream &operator<<(ostream &os, const SortedLinkedList &list) {
    // George doesn't do this code.
    os << "[";
    const Node *curr = list.head;
    while (curr != nullptr) {
        os << curr->data;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }
    os << "]";
    return os;
}

int SortedLinkedList::operator[](int index) {
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

// ------------------ DESTRUCTOR.
SortedLinkedList::~SortedLinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// --------------------------------------------- GET ELEMENT FUNCTION.
bool getElement(string &element) {
    getline(cin, element);
    try {
        // Check if the input is empty.
        if (element.empty()) {
            throw invalid_argument("Invalid Input!");
        }
        else {
            for (int i = 0; i < element.size(); ++i) {
                if (i == 0 && element[i] == '-') continue;                 // Check if the element is negative.
                else if (element[i] < '0' || element[i] > '9') {           // Check if the element is a number.
                    throw invalid_argument("Invalid Input!");
                }
            }
        }
    }

    catch (const invalid_argument &e) {
        cout << "\nError: " << e.what() << endl;
        return false;
    }

    return true;
}

// --------------------------------------------- MAIN FUNCTION.
int main() {
    string choice, element;
    SortedLinkedList list;

    cout << "\n<------------------------------- WELCOME TO OUR LINKED LIST! ------------------------------->\n";
    while (true) {

        // Show the user the options to choose from and get the user's choice.
        while (true) {
            cout << "\nWhat do you want to do?\n 1. Inserting Elements into the Sorted Linked List.\n"
                    " 2. Accessing Elements Using Index Operator.\n 3. Deleting Elements from the Linked List."
                    "\n 4. Print the list.\n 5. Exit.\nEnter your choice (1-5):";
            getline(cin, choice);

            if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") break;
            cout << "Invalid Input!\n";
        }

        // Inserting Elements into the Sorted Linked List.
        if (choice == "1") {
            do {
                cout << "Please enter element to insert.\n";
            } while (!getElement(element));

            list.insert(stoi(element));
            cout << "Inserted successfully!\n";
        }

        // Accessing Elements Using Index Operator.
        else if (choice == "2") {
            do {
                cout << "Please enter index of element you want to access.\n";
            } while (!getElement(element));

            try {
                if (list[stoi(element)])
                    cout << "Element at index " << stoi(element) << " is " << list[stoi(element)] << "\n";
            }
            catch (const out_of_range &e) {
                cout << "\nError: " << e.what() << endl;
            }
        }

        // Deleting Elements from the Linked List.
        else if (choice == "3") {
            do {
                cout << "Please enter index of element you want to delete.\n";
            } while (!getElement(element));

            list.remove(stoi(element));
            cout << "Deleted successfully!\n";
        }

        // Print the list.
        else if (choice == "4") cout << "Sorted Linked List: " << list << "\n";

        // Exit the program.
        else if (choice == "5") break;
    }

    cout << "\nTHANKS FOR USING OUR APPLICATION :)" << endl;
    return 0;
}