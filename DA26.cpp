#include <stdio.h>
#include <stdbool.h>

#define V 5 

bool is_safe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (is_safe(graph, color, v, c)) {
            color[v] = c; 

            if (graph_coloring_util(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0;
        }
    }

    return false; 
}

void graph_coloring(int graph[V][V], int m) {
    int color[V]; 
    for (int i = 0; i < V; i++) {
        color[i] = 0; 
    }

    if (graph_coloring_util(graph, m, color, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int m = 3; 
    graph_coloring(graph, m);

    return 0;
}
