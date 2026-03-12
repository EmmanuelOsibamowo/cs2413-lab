/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */


#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int checkAVL(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) {
        return 0;
    }

    /* Check strict BST property */
    if ((long long)node->val <= min || (long long)node->val >= max) {
        return -1;
    }

    int leftHeight = checkAVL(node->left, min, node->val);
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkAVL(node->right, node->val, max);
    if (rightHeight == -1) {
        return -1;
    }

    int diff = leftHeight - rightHeight;
    if (diff < -1 || diff > 1) {
        return -1;
    }

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, -9223372036854775807LL - 1, 9223372036854775807LL) != -1;
}
