#include "graph.h"

/**
 * Checks if the graph contains at least one triangle (3-clique).
 * Returns 1 if a triangle exists, 0 otherwise.
 */
int has_triangle(Graph* g) {
    int n = g->num_nodes;

    // We need at least 3 nodes to form a triangle
    if (n < 3) {
        return 0;
    }

    // Iterate through all possible triplets of nodes (i, j, k)
    // We use i < j < k to ensure we pick distinct nodes and don't duplicate checks
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Only proceed if there is an edge between i and j
            if (g->adj[i][j] == 1) {
                for (int k = j + 1; k < n; k++) {
                    // Check if node k completes the triangle with i and j
                    if (g->adj[j][k] == 1 && g->adj[k][i] == 1) {
                        return 1; // Triangle found!
                    }
                }
            }
        }
    }

    // If we've checked all triplets and found nothing
    return 0;
}
