# 📌 Sorted Linked List

## 📜 Description
This project implements a **Sorted Linked List** that maintains its elements in sorted order using **insertion sort logic**. The list supports insertion, deletion, overloaded operators, and proper memory management.

## ✨ Features
- **Insertion (`insert(n)`)**: Adds `n` while keeping the list sorted.
- **Deletion (`remove(n)`)**: Removes the element at index `n` (0-based index). If `n` is out of bounds, no changes occur.
- **Overloaded Operators:**
  - `<<` (Output Operator): Prints the linked list in a formatted way.
  - `[]` (Index Operator): Returns the element at a given index. If out of bounds, an exception is thrown.
- **Memory Management**: Ensures proper deallocation of memory when deleting nodes or destroying the list.

## 🏗️ Usage & Example Test Cases

### **Inserting Elements into the Sorted Linked List**
```cpp
L.insert(5);    // L = [5]
L.insert(8);    // L = [5, 8] 

L.insert(7);    // L = [5, 7, 8] 
L.insert(6);    // L = [5, 6, 7, 8] 
L.insert(6);    // L = [5, 6, 6, 7, 8] 
cout << L;      // Output: [5, 6, 6, 7, 8]
```

### **Accessing Elements Using Index Operator**
```cpp
cout << L[2];  // Output: 6 
cout << L[10]; // Throws out_of_range exception 
```

### **Deleting Elements from the Linked List**
```cpp
// Starting List: L = [5, 6, 6, 7, 8]
L.remove(0);   // L = [6, 6, 7, 8] 
cout << L;
// Output: [6, 6, 7, 8]

L.remove(100); // No change (out of bounds) 
cout << L;     
// Output: [6, 6, 7, 8] 

L.remove(2);   // L = [6, 6, 8] 
cout << L;
// Output: [6, 6, 8] 

L.remove(2);   // L = [6, 6] 
cout << L;
// Output: [6, 6] 
```

## 👨‍💻 Contributing
Contributions are welcome! Feel free to fork the repo and submit a pull request.

## ✍️ Authors
- Esraa Emary Abd El-Salam: [GitHub](https://github.com/esraa-emary) - [LinkedIn](https://www.linkedin.com/in/esraa-emary-b372b8303/)
- Mariam Badr Yehia: [GitHub](https://github.com/Mariam-Badr-MB) - [LinkedIn](https://www.linkedin.com/in/mariambadr13/)
- George Malak Magdy:  [GitHub](https://github.com/GeorgeMalakM) - [LinkedIn](https://www.linkedin.com/in/george-malak204/)
- John Ayman Demian:  [GitHub](https://github.com/Johnayman1) - [LinkedIn](https://www.linkedin.com/in/john-ayman-aa30842b7/)
- Mohammed Atef Abd El-Kader: [GitHub](https://github.com/Mohammed-3tef) - [LinkedIn](https://www.linkedin.com/in/mohammed-atef-b0a408299/)

## 📜 License
This project is licensed under the MIT License.

---
✨ **Developed with ❤️ in C++** ✨
