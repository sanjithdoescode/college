#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create an empty list
struct Node* createEmptyList() {
    return NULL;
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node after a specific node (given its data)
struct Node* insertAfterNode(struct Node* head, int dataToFind, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = newData;
    newNode->next = NULL;

    struct Node* current = head;
    while (current != NULL && current->data != dataToFind) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found.\n", dataToFind);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete from the beginning.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node from the beginning deleted.\n");
    return head;
}

// Function to delete the node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete from the end.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        printf("Last node deleted (the only node).\n");
        return NULL;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    struct Node* lastNode = current->next;
    current->next = NULL;
    free(lastNode);
    printf("Node from the end deleted.\n");
    return head;
}

// Function to delete a node with a specific data value
struct Node* deleteNode(struct Node* head, int dataToDelete) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return head;
    }

    if (head->data == dataToDelete) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node with data %d deleted from the beginning.\n", dataToDelete);
        return head;
    }

    struct Node* current = head;
    struct Node* previous = NULL;
    while (current != NULL && current->data != dataToDelete) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found.\n", dataToDelete);
        return head;
    }

    previous->next = current->next;
    free(current);
    printf("Node with data %d deleted.\n", dataToDelete);
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory of the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("List memory freed.\n");
}

int main() {
    struct Node* head = createEmptyList();

    // Insertion Operations
    head = insertAtBeginning(head, 10); // List: 10 -> NULL
    head = insertAtEnd(head, 20);       // List: 10 -> 20 -> NULL
    head = insertAtBeginning(head, 5);  // List: 5 -> 10 -> 20 -> NULL
    head = insertAtEnd(head, 30);       // List: 5 -> 10 -> 20 -> 30 -> NULL
    displayList(head);

    head = insertAfterNode(head, 10, 15); // List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
    displayList(head);

    head = insertAfterNode(head, 100, 99); // Node not found
    displayList(head);

    // Deletion Operations
    head = deleteFromBeginning(head); // List: 10 -> 15 -> 20 -> 30 -> NULL
    displayList(head);

    head = deleteFromEnd(head);       // List: 10 -> 15 -> 20 -> NULL
    displayList(head);

    head = deleteNode(head, 15);      // List: 10 -> 20 -> NULL
    displayList(head);

    head = deleteNode(head, 100);     // Node not found
    displayList(head);

    head = deleteFromBeginning(head); // List: 20 -> NULL
    displayList(head);

    head = deleteFromEnd(head);       // List: NULL
    displayList(head);

    head = deleteFromBeginning(head); // List is empty
    displayList(head);

    // Free allocated memory
    freeList(head); // head is NULL here, so it's safe

    return 0;
}

/*

Sample Output

Linked List: 5 -> 10 -> 20 -> 30 -> NULL
Linked List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
Node with data 100 not found.
Linked List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
Node from the beginning deleted.
Linked List: 10 -> 15 -> 20 -> 30 -> NULL
Node from the end deleted.
Linked List: 10 -> 15 -> 20 -> NULL
Node with data 15 deleted.
Linked List: 10 -> 20 -> NULL
Node with data 100 not found.
Linked List: 10 -> 20 -> NULL
Node from the beginning deleted.
Linked List: 20 -> NULL
Last node deleted (the only node).
List is empty.
List is empty, cannot delete from the beginning.
List is empty.
List memory freed.

*/
