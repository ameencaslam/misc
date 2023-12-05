#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;          // Data of the node
    struct Node* next; // Pointer to the next node
};

// Global head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert in the middle
void insertInMiddle(int data, int position) {
    if (position <= 0) {
        // Invalid position, do nothing
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        // Insert at the beginning
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* current = head;
    int currentPosition = 1;

    // Traverse to the node before the desired position
    while (currentPosition < position - 1 && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        // Invalid position, do nothing
        return;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to display the linked list
void displayList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Example usage
    insertAtBeginning(10);
    insertAtEnd(30);
    insertInMiddle(20, 2);

    // Display the linked list
    printf("Linked List: ");
    displayList();

    return 0;
}
