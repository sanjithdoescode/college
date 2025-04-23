#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning (used for building the initial list)
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node into a sorted linked list
struct Node* sortedInsert(struct Node* sortedHead, struct Node* newNode) {
    // Case 1: Empty sorted list or newNode should be the new head
    if (sortedHead == NULL || sortedHead->data >= newNode->data) {
        newNode->next = sortedHead;
        return newNode; // New head
    }

    // Case 2: Insert newNode in the middle or at the end
    struct Node* current = sortedHead;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return sortedHead; // Head remains the same
}

// Function to sort a singly linked list using Insertion Sort
struct Node* sortLinkedList(struct Node* head) {
    struct Node* sortedHead = NULL; // Initialize the sorted list as empty
    struct Node* current = head;    // Pointer to traverse the original list

    while (current != NULL) {
        // Store the next node before modifying the current node's links
        struct Node* nextNode = current->next;

        // Insert the current node into the sorted list
        sortedHead = sortedInsert(sortedHead, current);

        // Move to the next node in the original list
        current = nextNode;
    }

    return sortedHead; // Return the head of the sorted list
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
}

int main() {
    struct Node* head = NULL; // Start with an empty list

    // Insert some nodes in unsorted order
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 50);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 40);

    printf("Original ");
    displayList(head);

    // Sort the linked list
    head = sortLinkedList(head);

    printf("Sorted ");
    displayList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}

/*

Expected Output:

Original Linked List: 40 -> 20 -> 50 -> 10 -> 30 -> NULL
Sorted Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

Explanation:
struct Node: Same structure as before to represent a node with data and a pointer to the next node.
createNode(int data): A helper function to create a new node, allocating memory and setting its data and next pointer to NULL. Includes error handling for memory allocation failure.
insertAtBeginning(struct Node* head, int data): A simple function to insert a node at the beginning. Used here just to quickly build the initial unsorted list.
sortedInsert(struct Node* sortedHead, struct Node* newNode): This is the core of the insertion sort algorithm for the linked list.
It takes the head of the already sorted list (sortedHead) and the newNode to be inserted.
Case 1: Empty sorted list or newNode is smaller than the current head: If the sortedHead is NULL (meaning the sorted list is empty) or the newNode's data is less than or equal to the sortedHead's data, the newNode becomes the new head of the sorted list.
Case 2: Insert in the middle or at the end: It traverses the sortedHead list to find the correct position to insert the newNode. The loop continues as long as there is a next node (current->next != NULL) and the next node's data is less than the newNode's data (current->next->data < newNode->data). This ensures that current will point to the node before where newNode should be inserted.
Once the correct position is found, the newNode's next pointer is set to point to the node that was originally after current (current->next). Then, current's next pointer is updated to point to the newNode. This splices the newNode into the sorted list.
It returns the sortedHead (which might have changed if the new node became the head).
sortLinkedList(struct Node* head): This function implements the overall insertion sort logic.
It initializes an empty sortedHead.
It iterates through the original linked list using the current pointer.
In each iteration:
It stores the current node's next pointer in nextNode before potentially modifying current->next. This is crucial to avoid losing the rest of the original list.
It calls sortedInsert to insert the current node into the sortedHead list. Importantly, sortedInsert returns the potentially new head of the sorted list, so we update sortedHead.
It moves current to nextNode to process the next element from the original list.
Finally, it returns the sortedHead, which is the head of the fully sorted linked list.
displayList(struct Node* head): Helper function to print the contents of the list.
freeList(struct Node* head): Helper function to deallocate the memory used by the list nodes.
main():
Creates an empty linked list.
Inserts some unsorted data using insertAtBeginning.
Displays the original (unsorted) list.
Calls sortLinkedList to sort the list.
Displays the sorted list.
Calls freeList to clean up memory.
How Insertion Sort Works on a Linked List:
The beauty of this approach is that we are not swapping data within the nodes. Instead, we are taking each node from the original unsorted list and re-linking it into its correct position in a new, sorted list. The original list is effectively consumed as we build the sorted lis

*/
