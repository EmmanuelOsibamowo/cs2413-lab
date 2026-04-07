#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
  // TODO: implement
        if (t1 == NULL && t2 == NULL) {
        return true;
    }
    if (t1 == NULL || t2 == NULL) {
        return false;
    }

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}
