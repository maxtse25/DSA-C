#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a Binary Search Tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search a given key in a given BST
Node* inorderTraversal(Node* root) {
    if (root != NULL) {

        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search a given key in a given BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    Node* found = search(root, 10);
    if (found != NULL)
        printf("Element %d found in the BST.\n", found->data);
    else
        printf("Element not found in the BST.\n");

    return 0;
}