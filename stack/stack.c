#include "stack.h"

const u32 MAX_CAPACITY_STACK = 1000000;

// --- Dynamic Array Stack ---

dynamic_stack* array_stack_create(u32 initial_capacity)
{
   // allocates in memory the size for the enum of dynamic-array 
   dynamic_stack* stack = malloc(sizeof(dynamic_stack));

   if (stack == NULL) {
      printf("\nThe stack is null, memory error\n");
      return stack;
   }

   // initiates the stack -> alocates the data depending on capacity
   stack->data = malloc(initial_capacity * sizeof(*stack->data)); // this sizeof() is getting u32 defined in dynamic_array
                                          // if it was stack->data it would get the size of the pointer, not the data
   stack->size = 0;
   stack->current_capacity = initial_capacity;
   stack->max_capacity = MAX_CAPACITY_STACK;

   return stack;
}

void array_stack_destroy(dynamic_stack* stack)
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

int resize_dynamic_array(dynamic_stack* array)
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

int array_stack_pop(dynamic_stack* stack)
{
   if(array_stack_is_empty(stack))
   {
      printf("the stack is empty, cant pop\n");
      return -1;
   }
   else
   {
      printf("Poped: %d\n", stack->data[stack->size - 1]);
      stack->size--;
      return 0;
   }
}

int array_stack_push(dynamic_stack* stack, int data)
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

bool array_stack_is_empty(dynamic_stack* stack)
{
   if(stack->size == 0) return true;
   else return false;
}

bool array_stack_is_full(dynamic_stack* stack)
{
   if(stack->size == stack->current_capacity) return true;
   else return false;
}

int array_stack_peek(dynamic_stack* stack)
{
   if (array_stack_is_empty(stack))
   {
      printf("stack is empty, there is no top element\n");
      return -1;
   }

   printf("Top element: %d\n", stack->data[stack->size - 1]);
   return 0;
}

void array_stack_capacity(dynamic_stack* stack)
{
   printf("stack size: %u\n", stack->size);
   printf("stack capacity: %u\n", stack->current_capacity);
}

void print_possible_options()
{
   printf("These are the possible operation:\n\n");
   printf("1.push    \tadds top\n2.pop     \tremove top\n3.peek    \tsee top value\n");
   printf("4.size    \tshows stack size and capacity\n");
   printf("5.isEmpty \tsee if is empty\n6.destroy \tdestroy stack and go back to menu\n\n");
}

int stack_array_ui()
{
   u32 stack_size = 0;
   bool valid_option = false;
   // User interface to print possibilities
   printf("==// Stack //==\n");
   printf("A stack is a data structure that works with lifo (last in first out).\n");
   printf("So you can only add(push), or remove(pop) from the top.\n");
   printf("To a stack of size 4 it will look somethign like this:\n\n");
   printf("\t|\t->\t|\t->\t|\t->\t|\t->\t|\t->\t|\n");
   printf("\t|\t->\t|\t->\t|\t->\t2\t->\t|\t->\t|\n");
   printf("\t|\t->\t|\t->\t1\t->\t1\t->\t1\t->\t|\n");
   printf("\t|\t->\t0\t->\t0\t->\t0\t->\t0\t->\t0\n\n");
   print_possible_options();
   printf("First, choose the starting size of the stack, the amount of \"things\" that will fit inside the stack:\n");

   // get stack size
   while(valid_option == false) {
      printf("stack size: ");
      valid_option = true;

      // see if it is a valid input
      if (scanf("%u", &stack_size) == 1)
      {
         // see if number is within limits
         if (stack_size > MAX_CAPACITY_STACK)
         {
            printf("the stack cannot be this big, the max size is 1 million\n");
            valid_option = false;
         }
         else if (stack_size < 1)
         {
            printf("the stack cannot be zero or negative\n");
            valid_option = false;
         }
         else
            valid_option = true;
      }
      else
      {
         printf("not a valid number\n");
         while (getchar() != '\n')
            ;
         valid_option = false;
      }
   }

   // creates stack and checks if it is allocated in memory
   dynamic_stack* stack = array_stack_create(stack_size);
   if (stack == NULL) return -1;

   // print stack possible operations
   int choice = -1;
   printf("\nYou created a stack with %u capacity\n\n", stack_size);
   printf("choose an option:\n");
   printf("0.list options details\n1.push\n2.pop\n3.peek\n4.size\n5.isEmpty\n6.destroy\n");
   
   while(choice != 6)
   {
      printf("\nchoose an option: ");
      if (scanf("%d", &choice) != 1)
         while (getchar() != '\n')
            ;

      switch (choice)
      {
         case 0:
            print_possible_options();
            break;
         case 1:
            int added_int = 0;
            printf("number to add to stack: ");
            while (scanf("%d", &added_int) != 1)
            {
               printf("that is not a numbern, try again: ");
               while (getchar() != '\n')
                  ;
            }
            if (array_stack_push(stack, added_int) == 0)
               printf("operation succeded\n");
            else
               printf("error, operation failed\n");
            break;
         case 2:
            if (array_stack_pop(stack) == 0)
               printf("operation succeded\n");
            else
               printf("error, operation failed\n");
            break;
         case 3:
            array_stack_peek(stack);
            break;
         case 4:
            array_stack_capacity(stack);
            break;
         case 5:
            if (array_stack_is_empty(stack))
               printf("Stack is empty!\n");
            else
               printf("Stack is not empty!\n");
            break;
         case 6:
            array_stack_destroy(stack);
            printf("Stack destroyed, operation successfull");
            break;
         default:
            printf("this is not a valid answer, try again: ");
            break;
      }
   }

   // not supposed to get here withou destroying stack, but for containment
   array_stack_destroy(stack);
   return 0;
}