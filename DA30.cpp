#include <stdio.h>
#include <stdbool.h>

#define V 5 

bool isSafe(int graph[V][V], int path[], int pos, int v) {
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

bool hamiltonianUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(graph, path, pos, v)) {
            path[pos] = v; 

            if (hamiltonianUtil(graph, path, pos + 1)) {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false; 
}

void hamiltonianCircuit(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1; 
    }

    path[0] = 0;

    if (hamiltonianUtil(graph, path, 1)) {
        printf("Hamiltonian Circuit exists: ");
        for (int i = 0; i < V; i++) {
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]); 
    } else {
        printf("No Hamiltonian Circuit exists\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    hamiltonianCircuit(graph);
    return 0;
}
