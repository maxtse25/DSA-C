#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are initially red
    newNode->left = newNode->right = newNode-> parent = NULL;
    return newNode;
}

/* Do rotation under the four cases:
case 0: Z = root
case 1: Z.uncle = red -> recolor
case 2: Z.uncle = black(triangle) -> rotate Z.parent
case 3: Z.uncle = black(line) -> rotate Z.grandparent & recolor

Time complexity:
Insert: O(log n)
Color red: O(1)
Fix violations:
    Constant # of:
        a. Recolor: O(1)
        b. Rotation: O(1)
*/

// Right Rotation
void rotateRight(Node **root, Node* y) {
    Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }

    x->right = y;
    y->parent = x;
}

// Left Rotation
void rotateLeft(Node **root, Node* x) {
    
}
// Insertion
/* Deletion 
1. Transplate: hleps move subtrees within the red-black tree
2. Delete
3. Delete_fixup
*/