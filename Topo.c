#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


struct Node {
    int vertex;
    struct Node* next;
};


struct Graph {
    struct Node* adjList[MAX_VERTICES];
};


struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}


void topologicalSortUtil(int v, struct Graph* graph, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            topologicalSortUtil(adjVertex, graph, visited, stack, stackIndex);
        }
        temp = temp->next;
    }

    stack[(*stackIndex)++] = v;
}


void topologicalSort(struct Graph* graph, int vertices) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackIndex = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, graph, visited, stack, &stackIndex);
        }
    }

    printf("Topological Sort: ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int vertices = 6;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Graph:\n");
    printf("5 -> 2\n");
    printf("|    |\n");
    printf("v    v\n");
    printf("0    3\n");
    printf("|    /\n");
    printf("v   /\n");
    printf("4 /\n");
    printf("|/\n");
    printf("1\n");

    topologicalSort(graph, vertices);

    return 0;
}
