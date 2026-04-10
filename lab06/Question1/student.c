#include "graph.h"
// Question 1 — Count Number of Edges
// Description

// Write a function that counts how many edges are in an undirected graph.
// The graph is stored as an adjacency matrix. (In this lab, we use an adjacency matrix.)
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_edges(Graph* g) {
    int count = 0;
    
    // Iterate through each row of the adjacency matrix
    for (int i = 0; i < g->num_nodes; i++) {
        // Iterate through each column of the adjacency matrix
        for (int j = 0; j < g->num_nodes; j++) {
            // If there is an edge (1), increment the counter
            if (g->adj[i][j] == 1) {
                count++;
            }
        }
    }

    // Since it's an undirected graph, adj[u][v] and adj[v][u] 
    // represent the same single edge. We divide by 2 to get the actual count.
    return count / 2;
}
















// Tips:
// Explanation
// The graph is stored as an adjacency matrix. Since the graph is undirected, every edge appears twice in the matrix:

// once at adj[u][v]
// once at adj[v][u]

// So when counting all 1s in the matrix, you must divide the total by 2.
