# Understanding Singly Linked Lists

A Singly Linked List is a linear data structure where each element (called a node) contains two parts:
- Data: The actual value stored in the node. This can be any data type (integer, float, character, structure, etc.).
- Pointer (or Link): A pointer that points to the next node in the sequence.
Think of it like a chain of interconnected boxes. Each box holds some information and an arrow pointing to the next box in the line.

---

## Key Characteristics:
- Dynamic Size: Linked lists can grow or shrink dynamically during program execution, unlike arrays which have a fixed size.
- Non-Contiguous Memory Allocation: Nodes are not necessarily stored in contiguous memory locations. The links are what connect them.
- Sequential Access: To access a specific node, you must start from the beginning of the list and traverse through the links.
- Efficient Insertions and Deletions (in certain cases): Inserting or deleting a node can be more efficient than with arrays, especially in the middle of the list, as you only need to update pointers rather than shifting elements.

---

## Visual Representaion

+-------+     +-------+     +-------+     +-------+
| Data  | --> | Data  | --> | Data  | --> | NULL  |
|-------|     |-------|     |-------|     |-------|
| Next  |     | Next  |     | Next  |     | Next  |
+-------+     +-------+     +-------+     +-------+
   ^             ^             ^             ^
   |             |             |             |
 HEAD        Node 1        Node 2        Node 3

- HEAD (or Start or Root): A pointer that points to the first node of the list. This is the entry point to the list.
- NULL: The pointer in the last node points to NULL, indicating the end of the list.

---

Linked list is one of the most important data structures. We often face situations, where the data
is dynamic in nature and number of data can‘t be predicted or the number of data keeps changing
during program execution. Linked lists are very useful in this type of situations.
The implementation of a linked list in C is done using pointers
A linked list is made up of many nodes which are connected in nature. Every node is mainly
divided into two parts, one part holds the data and the other part is connected to a different node. It
is similar to the picture given below.
