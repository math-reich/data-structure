#include "../data-structure.h"

#ifndef STACK_H
#define STACK_H

typedef struct
{
   int* data;
   u32 size;
   u32 current_capacity;
   u32 max_capacity;
} dynamic_stack;

extern const u32 MAX_CAPACITY_STACK;

// stack dynamic array
int stack_array_ui();
dynamic_stack* array_stack_create(u32 initial_capacity);
void array_stack_destroy(dynamic_stack* stack);
int resize_dynamic_array(dynamic_stack* array);
int array_stack_push(dynamic_stack* stack, int data);
int array_stack_pop(dynamic_stack* stack);
int array_stack_peek(dynamic_stack* stack);
bool array_stack_is_empty(dynamic_stack* stack);
bool array_stack_is_full(dynamic_stack* stack);
void print_possible_options();
void array_stack_capacity(dynamic_stack* stack);

// stack using linked-list

#endif