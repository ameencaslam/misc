#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Global head pointer
struct node* head = NULL;

// Function to insert a node at the beginning of the doubly linked list
void insert(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = (head == NULL) ? NULL : head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// Function to display the doubly linked list in forward direction
void display() {
    printf("Doubly Linked List (Forward): ");
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("\n1. Insert a node\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                display();
                break;
            case 3:
                // Free allocated memory
                while (head != NULL) {
                    struct node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
