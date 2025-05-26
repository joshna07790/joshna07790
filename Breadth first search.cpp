#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Breadth First Search function
void bfs(int adjMatrix[MAX][MAX], int startVertex, int numVertices) {
    int i, currentVertex;

    visited[startVertex] = 1;
    enqueue(startVertex);

    printf("BFS traversal: ");

    while (front <= rear) {
        currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int adjMatrix[MAX][MAX];
    int numVertices, i, j, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", numVertices - 1);
    scanf("%d", &startVertex);

    // Initialize visited array
    for (i = 0; i < numVertices; i++)
        visited[i] = 0;

    bfs(adjMatrix, startVertex, numVertices);

    return 0;
}

