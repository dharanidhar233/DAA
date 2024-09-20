#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4  

int cost[N][N] = {
    {10, 19, 8, 15},
    {10, 18, 7, 17},
    {13, 16, 9, 14},
    {12, 19, 20, 8}
};

typedef struct {
    int level;      
    int assigned[N]; 
    int cost;       
    int bound;      
} Node;

int calculateBound(Node u) {
    int total = u.cost;

    bool jobAssigned[N] = {false};
    for (int i = 0; i < u.level; i++) {
        jobAssigned[u.assigned[i]] = true;
    }

    for (int i = 0; i < N; i++) {
        if (!jobAssigned[i]) {
            int min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < N; j++) {
                if (!jobAssigned[j]) {
                    if (cost[i][j] < min1) {
                        min2 = min1;
                        min1 = cost[i][j];
                    } else if (cost[i][j] < min2) {
                        min2 = cost[i][j];
                    }
                }
            }
            total += min1 + min2;  
        }
    }
    return total;
}

void branchAndBound() {
    Node queue[100]; 
    int front = -1, rear = -1;
    int minCost = INT_MAX;

    Node root = {0, {-1, -1, -1, -1}, 0, 0};
    root.bound = calculateBound(root);
    
    queue[++rear] = root;

    while (front != rear) {
        Node u = queue[++front]; 

        if (u.level == N) {
            if (u.cost < minCost) {
                minCost = u.cost;
            }
            continue;
        }

        for (int j = 0; j < N; j++) {
            if (u.assigned[j] == -1) { 
                Node v = u; 
                v.assigned[u.level] = j; 
                v.cost += cost[u.level][j]; 
                v.level++; 
                v.bound = calculateBound(v); 
                if (v.bound < minCost) {
                    queue[++rear] = v;
                }
            }
        }
    }

    printf("Minimum cost: %d\n", minCost);
}

int main() {
    branchAndBound();
    return 0;
}
