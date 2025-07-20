#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch() in Turbo C, if needed for menu

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int data, int position) {
    struct Node* newNode;
    struct Node* temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        if (position == 1) {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        } else {
            temp = head;
            for (i = 1; i < position - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            // If position is beyond the end, insert at the end
            if (temp->next == head && i < position - 1) {
                 printf("Position out of bounds, inserting at end.\n");
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteNode(int key) {
    struct Node* current;
    struct Node* prev;
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    // Case 1: Only one node in the list
    if (head->data == key && head->next == head) {
        free(head);
        head = NULL;
        printf("Node with key %d deleted. List is now empty.\n", key);
        return;
    }

    current = head;
    prev = NULL;

    // Traverse to find the node or reach the head again
    do {
        if (current->data == key) {
            break; // Node found
        }
        prev = current;
        current = current->next;
    } while (current != head);

    // Case 2: Node not found
    if (current->data != key) {
        printf("Node with key %d not found in the list.\n", key);
        return;
    }

    // Case 3: Deleting the head node (multiple nodes)
    if (current == head) {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        free(current);
        printf("Head node with key %d deleted.\n", key);
    }
    // Case 4: Deleting a node in the middle or at the end
    else {
        prev->next = current->next;
        free(current);
        printf("Node with key %d deleted.\n", key);
    }
}

void displayList() {
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Circular Linked List: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, position, key;

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear input buffer for Turbo C
        // while (getchar() != '\n'); // Uncomment if you face issues with scanf and subsequent inputs

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert (1 for beginning): ");
                scanf("%d", &position);
                insertNode(data, position);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free remaining nodes before exiting
    if (head != NULL) {
        struct Node* current = head->next;
        struct Node* temp;
        while (current != head) {
            temp = current;
            current = current->next;
            free(temp);
        }
        free(head);
        head = NULL;
    }

    return 0;
}
