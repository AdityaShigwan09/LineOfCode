#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Function to initialize adjacency matrix
void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
}

// Function to print the adjacency matrix
void printAdjMatrix(int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the indegree of all vertices
void printIndegree(int vertices) {
    printf("Indegree of vertices:\n");
    for (int i = 0; i < vertices; i++) {
        int indegree = 0;
        for (int j = 0; j < vertices; j++) {
            indegree += adjMatrix[j][i];
        }
        printf("Vertex %d: %d\n", i, indegree);
    }
}

// Function to print the outdegree of all vertices
void printOutdegree(int vertices) {
    printf("Outdegree of vertices:\n");
    for (int i = 0; i < vertices; i++) {
        int outdegree = 0;
        for (int j = 0; j < vertices; j++) {
            outdegree += adjMatrix[i][j];
        }
        printf("Vertex %d: %d\n", i, outdegree);
    }
}

// Function to print the total degree of all vertices
void printTotalDegree(int vertices) {
    printf("Total degree of vertices:\n");
    for (int i = 0; i < vertices; i++) {
        int totalDegree = 0;
        for (int j = 0; j < vertices; j++) {
            totalDegree += adjMatrix[i][j] + adjMatrix[j][i];
        }
        printf("Vertex %d: %d\n", i, totalDegree);
    }
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initializeGraph(vertices);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printAdjMatrix(vertices);
    printIndegree(vertices);
    printOutdegree(vertices);
    printTotalDegree(vertices);

    getch();
}
