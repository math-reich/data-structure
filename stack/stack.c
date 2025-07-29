#include "stack.h"

// --- Dynamic Array Stack ---

dynamic_array* array_stack_create(u32 initial_capacity)
{
   // creates the dynamic-array in memory
   dynamic_array* stack = malloc(sizeof(dynamic_array));

   if (stack == NULL) {
      printf("\nThe stack is null, memory error\n");
      return 1;
   }

   // initiates the stack
   stack->data = malloc(initial_capacity * sizeof(*stack->data)); // this sizeof() is getting u32 defined in dynamic_array
                                          // if it was stack->data it would get the size of the pointer, not the data
   stack->size = 0;
   stack->current_capacity = initial_capacity;
   stack->max_capacity = MAX_CAPACITY_STACK;

   return stack;
}

void array_stack_destroy(dynamic_array* stack)
{
   if(stack->data != NULL)
   {
      free(stack->data);
   }

   if(stack != NULL)
   {
      free(stack);
   }
}

int array_stack_pop(dynamic_array* stack)
{
   if(array_stack_is_empty(stack))
   {
      printf("the stack is empty, cant pop");
      return -1;
   }
   else
   {
      printf("Poped: %d", stack->data[stack->size - 1]);
      stack->size--;
      return 0;
   }
}

int array_stack_push(dynamic_array* stack, int data)
{
   if(array_stack_is_full(stack))
   {
      int status = resize_dynamic_array(stack); 
      if(status == -1)
      {
         printf("Stack has reached max capacity\n");
         return -1;
      }
      if(status == -2)
      {
         printf("Not possible to resize array\n");
         return -2;
      }
   }
   stack->size++;
   stack->data[stack->size - 1] = data;
   return 0;
}

bool array_stack_is_empty(dynamic_array* stack)
{
   if(stack->size == 0) return true;
   else return false;
}

bool array_stack_is_full(dynamic_array* stack)
{
   if(stack->size == stack->current_capacity) return true;
   else return false;
}

int resize_dynamic_array(dynamic_array* array)
{
   if(array->current_capacity == MAX_CAPACITY_STACK) return -1;

   u32 new_capacity = 0; 
   if(array->current_capacity < 10)
   {
      new_capacity = array->current_capacity * 2;
   }
   else
   {
      if(array->current_capacity * 1.5 > MAX_CAPACITY_STACK)
      {
         new_capacity = MAX_CAPACITY_STACK;
      }
      else new_capacity = array->current_capacity * 1.5;
   }

   u32* temp_data = realloc(array->data, new_capacity * sizeof(*array->data));

   if(temp_data == NULL)
   {
      return -2;
   }

   array->data = temp_data;
   array->current_capacity = new_capacity;
   return 0;
}

// --- Stack ---