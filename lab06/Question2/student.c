#include "graph.h"
#include <stdbool.h>
// Description

// Write a function that counts how many nodes are isolated.
// A node is isolated if it has no edges connected to it.
// // The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_isolated(Graph* g) {
    int isolated_count = 0;

    // Iterate through every node in the graph
    for (int i = 0; i < g->num_nodes; i++) {
        bool has_edge = false;

        // Check the entire row for node 'i'
        for (int j = 0; j < g->num_nodes; j++) {
            // If we find a 1, this node is connected to something
            if (g->adj[i][j] == 1) {
                has_edge = true;
                break; // No need to check the rest of the row
            }
        }

        // If we finished the inner loop and found no 1s, the node is isolated
        if (!has_edge) {
            isolated_count++;
        }
    }

    return isolated_count;
}














// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.
