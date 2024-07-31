#include <stdio.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 10

// Define the stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

/* Function to initialize the stack by setting `top` to `-1`, indicating the stack is empty*/
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Function to add an item to the stack
void push(struct Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack is already full.\n");
        return;
    }
    s->items[++s->top] = item;
    printf("Pushed %d to stack\n", item);
}

// Function to remove an item from the stack
int pop(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->items[s->top--];
}

// Function to get the top item of the stack
int peek(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->items[s->top];
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Item popped from stack: %d\n", pop(&s));
    printf("Top item of the stack: %d\n", peek(&s));

    pop(&s);
    printf("Top item of the stack: %d\n", peek(&s));
    pop(&s);
    pop(&s);
    printf("Top item of the stack: %d\n", peek(&s));

    pop(&s);

    return 0;
}