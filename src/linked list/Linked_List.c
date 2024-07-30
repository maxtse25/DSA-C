# include <stdio.h>
# include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *next;
};

// Define the linked list structure
struct LinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// Function to initialize the linked list
void initList(struct LinkedList* list) {
    list -> head = NULL;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    struct Node* temp = list->head;
    // Traverse to the end of the list
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a specific value
void deleteNode(struct LinkedList* list, int key) {
    /* `temp` is a pointer used to traverse the list
    `prev` is a pointer to keep track of the previous node while traversing*/
    struct Node* temp = list->head;
    struct Node* prev = NULL;

    // Check if the node to be deleted is the head
    if (temp != NULL && temp->data == key) {
        list->head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present in the list
    if (temp == NULL) return;
    
    // If the key is found, unlink the node and free memory
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Test the linked list
int main() {
    struct LinkedList list;
    initList(&list);

    insertAtEnd(&list, 11);
    insertAtEnd(&list, 22);
    insertAtEnd(&list, 33);
    insertAtEnd(&list, 44);
    insertAtEnd(&list, 55);

    printf("Linked List: ");
    printList(&list);

    // Delete the head node
    deleteNode(&list, 11);
    printf("Linked list after deletion of the head node: ");
    printList(&list);

    // Delete the node with '33'
    deleteNode(&list, 33);
    printf("Linked list after deletion of the node with '33': ");
    printList(&list);

    return 0;
}