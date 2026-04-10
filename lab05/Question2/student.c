/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/* Helper: swap two integers */
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Helper: restore min-heap property moving up from index */
static void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

/* Helper: restore min-heap property moving down from index */
static void heapifyDown(int* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Allocate space for a min-heap of size k
    int* minHeap = (int*)malloc(k * sizeof(int));
    int currentSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (currentSize < k) {
            // Fill the heap until it reaches size k
            minHeap[currentSize] = nums[i];
            heapifyUp(minHeap, currentSize);
            currentSize++;
        } else {
            // If current number is larger than the smallest in our top-k,
            // replace the root and heapify down.
            if (nums[i] > minHeap[0]) {
                minHeap[0] = nums[i];
                heapifyDown(minHeap, k, 0);
            }
        }
    }

    // The root of the min-heap is the kth largest element
    int result = minHeap[0];
    free(minHeap);
    return result;
}
