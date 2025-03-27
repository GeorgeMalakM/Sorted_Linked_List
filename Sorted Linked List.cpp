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
    Node(int val);
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
    this->data = val;
    this->next = nullptr;
}

// --------------------------------------------- IMPLEMENTATION OF SORTED LINKED LIST CLASS.
// ------------------ CONSTRUCTOR.
SortedLinkedList::SortedLinkedList() {
    this->head = nullptr;
}

// ------------------ INSERT FUNCTION.
void SortedLinkedList::insert(const int value) {
    const auto newNode = new Node(value);

    // Case 1: Insert at the beginning or empty list
    if (this->head == nullptr || this->head->data >= value) {
        newNode->next = this->head;
        this->head = newNode;
        return;
    }

    // Case 2: Insert in the middle or end
    Node *curr = this->head;
    while (curr->next != nullptr && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

// ------------------ REMOVE FUNCTION

void SortedLinkedList::remove(int index) {
    if (!this->head) {  // Case 1: List is empty
        cout << "List is empty" << endl;
        return;
    }

    if (index < 0) {  // Case 2: Negative index
        cout << "Out of range" << endl;
        return;
    }

    // Case 3: Remove the first element
    if (index == 0) {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
        cout << "Removed Successfully....." << endl;
        return;
    }

    // Case 4: Remove from the middle or end
    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;

    while (curr != nullptr && count < index) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (!curr) {  // If the index is out of range
        cout << "Index out of range" << endl;
        return;
    }

    // Remove the node at the index
    prev->next = curr->next;
    delete curr;

    cout << "Removed Successfully....." << endl;
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
    Node *Current = this->head;
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
    Node *current = this->head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    this->head = nullptr;
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

// ----------------------------------------------- ANOTHER SOME HELPER FUNCTIONS
void runFromTerminal() {
    string choice, element;
    SortedLinkedList list;

    while (true) {
        // Show the user the options to choose from and get the user's choice.
        while (true) {
            cout << "\nWhat do you want to do?\n 1. Inserting Elements into the Sorted Linked List.\n"
                    " 2. Accessing Elements Using Index Operator.\n 3. Deleting Elements from the Linked List."
                    "\n 4. Print the list.\n 5. Exit From menu.\nEnter your choice (1-5):";
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
                cout << "Please, enter index of element you want to delete: ";
            } while (!getElement(element));

            list.remove(stoi(element));
        }

            // Print the list.
        else if (choice == "4") cout << "Sorted Linked List: " << list << "\n";

            // Exit the program.
        else if (choice == "5") break;
    }
}

void initializeInMAin() {
    SortedLinkedList L;

    cout << "// ---------------------------------------------Test Case 1\n\n";
    // Test Case 1: Inserting Elements into the Sorted Linked List
    cout << "\nTest Case 1: Inserting Elements into the Sorted Linked List\n";
    L.insert(5);                 // L = [5]
    L.insert(8);                 // L = [5, 8]

    L.insert(7);                 // L = [5, 7, 8]
    L.insert(6);                 // L = [5, 6, 7, 8]
    L.insert(6);                 // L = [5, 6, 6, 7, 8]
    cout << L << endl;                 // Output: [5, 6, 6, 7, 8]

    // Test Case 2: Accessing Elements Using Index Operator
    cout << "\nTest Case 2: Accessing Elements Using Index Operator\n";

    try {                              // Output: 6
        if (L[2]) cout << L[2] << "\n";
    }
    catch (const out_of_range &e) {
        cout << "\nError: " << e.what() << endl;
    }

    try {                              // Throws out_of_range exception
        if (L[10]) cout << L[10] << "\n";
    }
    catch (const out_of_range &e) {
        cout << "\nError: " << e.what() << endl;
    }

    // Test Case 3: Deleting Elements from the Linked List
    cout << "\nTest Case 3: Deleting Elements from the Linked List\n";
    cout << L << endl;                 // L = [5, 6, 6, 7, 8];

    L.remove(0);                 // L = [6, 6, 7, 8]
    cout << L << endl;                 // Output: [6, 6, 7, 8]
    L.remove(100);               // No change (out of bounds)
    cout << endl << L << endl;         // Output: [6, 6, 7, 8]
    L.remove(2);                 // L = [6, 6, 8]
    cout << L << endl;                 // Output: [6, 6, 8]
    L.remove(2);                 // L = [6, 6]
    cout << L << endl;                 // Output: [6, 6]


    cout << "\n// ---------------------------------------------Test Case 2\n\n";
    // Another test case: Inserting Elements into the Sorted Linked List
    cout << "\nTest Case 1: Inserting Elements into the Sorted Linked List\n";
    L.insert(-1);   // L = [-1, 6 , 6 ]
    L.insert(4);    // L = [-1 , 4, 6 , 6 ]
    L.insert(9);    // L = [-1,4, 6 , 6 ,9]
    L.insert(100);      // L = [-1,4, 6 , 6 ,9 ,100]
    cout << L << endl;                 // Output: [-1,4, 6 , 6 ,9 ,100]

    cout << "\nTest Case 2: Accessing Elements Using Index Operator\n";

    try {                              // Output: 100
        if (L[5]) cout << L[5] << "\n";
    }
    catch (const out_of_range &e) {
        cout << "\nError: " << e.what() << endl;
    }

    try {                              // Throws out_of_range exception
        if (L[10]) cout << L[10] << "\n";
    }
    catch (const out_of_range &e) {
        cout << "\nError: " << e.what() << endl;
    }

    // Test Case 3: Deleting Elements from the Linked List
    cout << "\nTest Case 3: Deleting Elements from the Linked List\n";
    cout << L << endl;                 // L = [-1, 4, 6, 6, 9, 100]

    L.remove(0);                 // L = [4, 6, 6, 9, 100]
    cout << L << endl;                 // Output: [4, 6, 6, 9, 100]
    L.remove(100);               // No change (out of bounds)
    cout << endl << L << endl;         // Output: [4, 6, 6, 9, 100]
    L.remove(4);                 // L = [4, 6, 6, 9]
    cout << L << endl;                 // Output: [4, 6, 6, 9]
    L.remove(5);                 // No change (out of bounds)
    cout << L << endl;                 // Output: [4, 6, 6, 9]
}

// --------------------------------------------- MAIN FUNCTION.
int main() {
    string choice;
    SortedLinkedList list;

    cout << "\n<------------------------------- WELCOME TO OUR LINKED LIST! ------------------------------->\n";
    while (true) {
        while (true) {
            cout << "\nWhat do you want to do?" << endl;
            cout << "1) Run From Terminal." << endl;
            cout << "2) Initialize in main." << endl;
            cout << "3) Exit." << endl;
            cout << "Please, enter your choice:";
            getline(cin, choice);

            // Check the validity of input.
            if (choice == "1" || choice == "2" || choice == "3") break;
            cout << "Invalid choice. Please, Try again." << endl;
        }

        // Run from the terminal.
        if (choice == "1") runFromTerminal();

        // Initialize in main.
        else if (choice == "2") initializeInMAin();
        else break;
    }

    cout << "\n------------------- THANKS FOR USING OUR APPLICATION -------------------" << endl;
    return 0;
}
