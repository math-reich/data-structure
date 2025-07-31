#include "../data-structure.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
   int* data;
   int rear;
   int front;
   int capacity;
} circular_queue;

circular_queue* array_queue_create(int capacity);
int array_queue_destroy(circular_queue* queue);
int array_queue_enqueue(int data);
int array_queue_dequeue();


#endif