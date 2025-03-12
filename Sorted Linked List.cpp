/*
* Authors:
    * Author1: Esraa Emary Abd El-Salam              ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader            ID: 20231143
    * Author3: Mariam Badr Yehia                     ID: 20230391
    * Author4: John Ayman Demian                     ID: 20230109
    * Author5: George Malak Magdy                    ID: 20231042

* Date: ? / 3 / 2025
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
    Node* next;
    Node(int val);    // Constructor
};

// --------------------------------------------- SORTED LINKED LIST CLASS.

class SortedLinkedList {
    Node* head;         // Pointer to the head of the list.
public:
    SortedLinkedList();    // Constructor

    void insert(int value);     // Insert a value in the list while the list remains sorted.
    void remove(int index);     // Delete node at a given index.

    // Overloaded operators.
    friend ostream& operator<<(ostream& os, const SortedLinkedList& list);
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
    Node* newNode = new Node(value);
    // Case 1: Insert at the beginning or empty list
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Insert in the middle or end
    Node* curr = head;
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

ostream& operator<<(ostream& os, const SortedLinkedList& list) {
    os << "[";
    Node* curr = list.head;
    while (curr != nullptr) {
        os << curr->data;
        if (curr->next != nullptr) os << ",";
        curr = curr->next;
    }
    os << "]";
    return os;
}

int SortedLinkedList::operator[](int index) {

}

// ------------------ DESTRUCTOR.

SortedLinkedList::~SortedLinkedList() {

}

// --------------------------------------------- MAIN FUNCTION.

int main() {
    SortedLinkedList l;
    l.insert(5);
    l.insert(10);
    l.insert(5);
    l.insert(1);
    l.insert(3);
    l.insert(4);
    l.insert(12);
    l.insert(-2);
    cout << "Sorted Linked List: " << l << endl;
    return 0;
}
