#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Define the queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    return q->rear == -1;
}

// Function to check of the queue is full
bool isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to add an item to the queue
void enqueue(struct Queue* q, int item) {
    if (isFull(q)) {
        printf("The queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    } 
    q->items[++q->rear] = item;
    printf("Inserted %d to the queue.\n", item);
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return -1;
    }
    int item = q->items[q->front];
    // Check if the queue has only one item
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    printf("Removed %d from the queue.\n", item);
    return item;
}

// Function to get the fron item of the queue
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty.]n");
        return -1;
    }
    return q->items[q->front];
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front item: %d\n", peek(&q));
    dequeue(&q);
    printf("Front item after one dequeue: %d\n", peek(&q));

    return 0;
}