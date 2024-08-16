#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

typedef struct RedBlackTree {
    Node *root;
} RedBlackTree;

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
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}
/* Insertion: When inserting a node, we insert it like a normal binary search tree and then fix and violations of the red-black tree properties*/
void fixViolation(Node **root, Node *z) {
    while (z != *root && z->parent->color == RED) {
        Node *grandparent = z->parent->parent;

        // Case1: parent is a left child
        if (z->parent == grandparent->left) {
            Node *y = grandparent->right; // If `z`'s parent is a left child of its grandparent, we check the color of `z`'s uncle `y`, which is the right child of `z`'s grandparent.

            // Case 1a: Uncle `y` is Red:
            /* If `y` is red, we jave a situation where both the parent and the uncle are red. Then solution is to:
                1. Recolor the parent and the uncle to black
                2. Recolor the grandparent to red
                3. Move `z` up to the grandparent node and continue the loop */
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            }

            // Case 1b: Uncle `y` is Black or NULL:
            /* If `y` is black or NULL:
                1. If `z` is a right child: we perform a left rotation around `z`'s parent to turn the situation into a case where `z` is a left child
                2. Recolor `z`'s parent to black and `z`'s grandparent to red
                3. Perform a right rotation around `z`'s grandparent */
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(root, z);
                    }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(root, z->parent->parent);
                }
        } else {
            // Case 2: Parent is a right child
            Node *y = z->parent->parent->left;

            // Case 2a: Uncle `y` is Red:
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
            // Case 2b: Uncle `y` is black or NULL;
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(root, z);
                }
                            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            rotateLeft(root, z->parent->parent); // If `z` is a left child: Perform a right rotation around `z`'s parent, recolor and then perform a left rotation around the grandparent
            }
        }
    }
    // Ensure root is black
    (*root)->color = BLACK;
}

void insert(Node **root, int data) {
    Node *z = createNode(data);
    Node *y = NULL; // `y` keeps track of the parent node where the new node `z` will be inserted
    Node *x = *root; // `x` is used to traverse the tree starting from the root

    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // Assigning the parent and inserting the node
    z->parent = y;

    if(y == NULL) {
        *root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    fixViolation(root, z);
}

// Utility Functions for Traversing and Printing
void inOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    RedBlackTree tree;
    tree.root = NULL;

    insert(&tree, 10);
    insert(&tree, 20);
    insert(&tree, 30);
    insert(&tree, 40);
    insert(&tree, 50);
    insert(&tree, 25);

    printf("In-order traversal of the tree: ");
    inOrderTraversal(tree.root);

    return 0;
}
