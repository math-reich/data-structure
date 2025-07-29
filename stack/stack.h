#include "../data-structure.h"

typedef struct
{
   int* data;
   u32 size;
   u32 current_capacity;
   u32 max_capacity;
} dynamic_array;

const u32 MAX_CAPACITY_STACK = 1000000;

// stack dynamic array
dynamic_array* array_stack_create(u32 initial_capacity);
void array_stack_destroy(dynamic_array* stack);
int array_stack_push(dynamic_array* stack, int data);
int array_stack_pop(dynamic_array* stack);
bool array_stack_is_empty(dynamic_array* stack);
bool array_stack_is_full(dynamic_array* stack);
int resize_dynamic_array(dynamic_array* array);

// stack using linked-list