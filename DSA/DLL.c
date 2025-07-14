#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// 1. Define the Node Structure for a Doubly Linked List
struct Node {
    int data;          // Data stored in the node
    struct Node* prev; // Pointer to the previous node (NEW!)
    struct Node* next; // Pointer to the next node
};

// Global head pointer, points to the first node of the list
// Initialized to NULL, meaning the list is empty
struct Node* head = NULL;

// --- Helper Function ---

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory can't be allocated
    }
    newNode->data = data;
    newNode->prev = NULL; // New node initially has no previous node
    newNode->next = NULL; // New node initially has no next node
    return newNode;
}

// --- Doubly Linked List Operations ---

// 1. Insertion at Head
void insertAtHead(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        // If the list is empty, new node is the head
        head = newNode;
    } else {
        // If list is not empty:
        newNode->next = head; // New node's next points to current head
        head->prev = newNode; // Current head's previous points to new node (DIFFERENCE from SLL)
        head = newNode;       // Head now points to the new node
    }
    printf("%d inserted at head.\n", data);
}

// 2. Insertion at Tail
void insertAtTail(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = newNode;
        printf("%d inserted at tail (list was empty).\n", data);
        return;
    }

    // Traverse to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Link the new node
    current->next = newNode; // Old tail's next points to new node
    newNode->prev = current; // New node's previous points to old tail (DIFFERENCE from SLL)
    printf("%d inserted at tail.\n", data);
}

// 3. Insertion Anywhere (at a specific position)
void insertAnywhere(int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        // If position is 1, it's effectively insertion at head
        insertAtHead(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int i;

    // Traverse to the node *before* the desired position
    // We need to stop at position - 1
    for (i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds. List has fewer than %d nodes.\n", position, position);
        free(newNode); // Free the allocated node as it won't be used
        return;
    }

    // Link the new node
    newNode->next = current->next; // New node's next points to current's next
    newNode->prev = current;       // New node's previous points to current (DIFFERENCE from SLL)
    current->next = newNode;       // Current's next points to new node

    // If there's a node after the new node, update its prev pointer
    if (newNode->next != NULL) {
        newNode->next->prev = newNode; // The node AFTER new node, its prev points to new node (DIFFERENCE from SLL)
    }
    printf("%d inserted at position %d.\n", data, position);
}

// 4. Deletion of a Node (by data value)
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;

    // Case 1: Node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Change head to the next node
        if (head != NULL) {
            head->prev = NULL; // New head's previous must be NULL (DIFFERENCE from SLL)
        }
        free(temp);         // Free memory of old head
        printf("%d deleted from head.\n", key);
        return;
    }

    // Case 2: Search for the key to be deleted
    // Move temp to the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("%d not found in the list. Cannot delete.\n", key);
        return;
    }

    // Unlink the node from the linked list
    // The node BEFORE temp, its next pointer now points to the node AFTER temp
    if (temp->prev != NULL) { // This check is mostly for safety, should always be true if temp is not head
        temp->prev->next = temp->next;
    }

    // The node AFTER temp, its previous pointer now points to the node BEFORE temp (DIFFERENCE from SLL)
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp); // Free memory
    printf("%d deleted from the list.\n", key);
}

// 5. Display the Doubly Linked List
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Linked List (Forward): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Optional: Displaying backward to show prev pointer functionality
    if (head != NULL) {
        current = head;
        // First, go to the last node
        while (current->next != NULL) {
            current = current->next;
        }

        printf("Linked List (Backward): ");
        while (current != NULL) {
            printf("%d <-> ", current->data);
            current = current->prev; // Traversing backward using 'prev' (DIFFERENCE from SLL)
        }
        printf("NULL\n");
    }
}

// --- Main Function (Menu Driven) ---

int main() {
    int choice, data, position;

    do {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert Anywhere\n");
        printf("4. Delete a Node (by value)\n");
        printf("5. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                insertAtHead(data);
                break;
            case 2:
                printf("Enter data to insert at tail: ");
                scanf("%d", &data);
                insertAtTail(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (1 for head): ");
                scanf("%d", &position);
                insertAnywhere(data, position);
                break;
            case 4:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 5:
                displayList();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                // In a real application, you'd free all remaining nodes here to prevent memory leaks
                // For simplicity in this example, we'll let the OS clean up on exit.
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
