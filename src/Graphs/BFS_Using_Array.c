#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph strcuture using an adjacency matrix
typedef struct Graph {
    bool adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Queue for BFS
typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue *q, int element) {
    if (q->rear == MAX_VERTICES - 1) {return;} // Queue if full
    if (q->front == -1) {q->front = 0;}
    q->items[++q->rear] = element;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {return -1;}
    int element = q->items[q->front];
    // Reset the queue to the initial state
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return element;
}

/*
Function to initialize the graph by setting all entries in the adjacency matrix to `false`
*/
void initGraph(Graph* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adj[i][j] = false;
        }
    }
}

/*
Function to set the corresponding elements in the adjacency matrix to `true` to represent an edge between two vertices
*/
void addEdge(Graph* g, int src, int dest) {
    g->adj[src][dest] = true;
    g->adj[dest][src] = true;
}

void bfs (Graph* g, int startVertex) {
    Queue q;
    initQueue(&q);

    // Initialize a boolean array `visited` to keep track of which vertices have been visited
    bool visited[MAX_VERTICES] = {false};

    visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph g;
    int numVertices = 4;
    initGraph(&g, numVertices);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);

    bfs(&g, 0);
    return 0;
}