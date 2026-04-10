/*
Question 1: Two Sum

Description:
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

For this lab, you should solve the problem using a hash-based idea.

Function:
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

Notes:
- Return a dynamically allocated array of size 2.
- Set *returnSize = 2 before returning.
- The returned array will be freed by the caller.

Example:
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]

Hint:
As you scan the array, for each nums[i], think about whether the value
(target - nums[i]) has already appeared before.
*/

#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

/* Computes hash index and handles negative numbers */
static int hash(int key) {
    int h = key % TABLE_SIZE;
    return (h < 0) ? h + TABLE_SIZE : h;
}

/* Inserts key (number) and value (index) into the table */
static void insert(Node* table[], int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx]; 
    table[idx] = newNode;
}

/* Searches for the complement in the table */
static int find(Node* table[], int key, int* value) {
    int idx = hash(key);
    Node* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            *value = curr->value;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

/* Cleans up allocated nodes to prevent memory leaks */
static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = { NULL };
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex;
        
        // Step 1: Check if the required partner is already in the hash map
        if (find(table, complement, &complementIndex)) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(table);
            return result;
        }
        
        // Step 2: If not found, store current number and move on
        insert(table, nums[i], i);
    }
    
    freeTable(table); // Cleanup if no solution (though problem guarantees one)
    *returnSize = 0;
    return NULL;
}
