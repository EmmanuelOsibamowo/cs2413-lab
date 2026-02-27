// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------


#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    if (k <= 0) return NULL;

    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (obj == NULL) return NULL;

    obj->data = (int*)malloc(sizeof(int) * k);
    if (obj->data == NULL) {
        free(obj);
        return NULL;
    }

    obj->capacity = k;
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0;

    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj == NULL) return false;
    if (myCircularQueueIsFull(obj)) return false;

    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj == NULL) return false;
    if (myCircularQueueIsEmpty(obj)) return false;

    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj == NULL) return -1;
    if (myCircularQueueIsEmpty(obj)) return -1;

    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj == NULL) return -1;
    if (myCircularQueueIsEmpty(obj)) return -1;

    int idx = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[idx];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj == NULL) return true;
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj == NULL) return false;
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj == NULL) return;
    free(obj->data);
    free(obj);
}
