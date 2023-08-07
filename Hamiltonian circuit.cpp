#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int hamiltonianPath[MAX_VERTICES];
bool isSafe(int v, int pos, int path[MAX_VERTICES]) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }
    return true;
}
bool hamiltonianUtil(int path[MAX_VERTICES], int pos) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]] == 1) {  
            return true; 
        }
        return false; 
    }
    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;
            if (hamiltonianUtil(path, pos + 1)) {
                return true;
            }
            path[pos] = -1; 
        }
    }
    return false;
}
bool hamiltonianCircuit() {
    int path[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        path[i] = -1;
    }
    path[0] = 0;
    if (hamiltonianUtil(path, 1)) {
        for (int i = 0; i < numVertices; i++) {
            hamiltonianPath[i] = path[i];
        }
        hamiltonianPath[numVertices] = path[0];
        return true;
    }
    return false;
}
int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix of the graph (1 if there's an edge, 0 otherwise):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    if (hamiltonianCircuit()) {
        printf("Hamiltonian Circuit Found:\n");
        for (int i = 0; i <= numVertices; i++) {
            printf("%d ", hamiltonianPath[i]);
        }
        printf("\n");
    } else {
        printf("Hamiltonian Circuit Not Found.\n");
    }
    return 0;
}
