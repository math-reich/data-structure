/* data-structure.c */

#include "data-structure.h"
#include "stack.h"

// functions declarations
int stack_array();

// --- Main function ---
int main(int argc, char *argv[])
{
   int options = -1;
   while(options != 0)
   {
      printf("\nChoose the Data Structure that you would like to test:\n");
      printf("1. Stack.\n");
      printf("2. Queue.\n");
      printf("3. Tree.\n");
      printf("0. Quit program.\n");

      scanf("%d", &options);

      switch(options)
      {
         case 1:
               stack_array();
               break;

         case 2:
               break;
         case 3:
               break;
         case 0:
               printf("Quiting...\n");
               return 0;
         default:
               printf("This is not a valid option, try again.\n");
               break;
      }
   }
   return 0;
}

// Data Structures using arrays

int stack_array()
{
   u32 stack_size = 0;
   printf("==// Stack //==\n");
   printf("A stack is a data structure that works with lifo (last in first out).\n");
   printf("So you can only add(push), or remove(pop) from the top.\n");
   printf("To a stack of size 4 it will look somethign like this:\n\n");
   printf("\t|\t->\t|\t->\t|\t->\t|\t->\t|\t->\t|\n");
   printf("\t|\t->\t|\t->\t|\t->\t2\t->\t|\t->\t|\n");
   printf("\t|\t->\t|\t->\t1\t->\t1\t->\t1\t->\t|\n");
   printf("\t|\t->\t0\t->\t0\t->\t0\t->\t0\t->\t0\n\n");
   printf("These are the possible operation:\n\n");
   printf("1.pop    \tremove top\n2.push   \tadds top\n3.peek   \tsee top value\n");
   printf("4.isEmpty\tsee if is empty\n5.destroy\tdestroy stack and go back to menu\n\n");
   printf("First, choose the starting size of the stack, the amount of \"things\" that will fit inside the stack:\n");

   do {
      printf("stack size: ");
      scanf("%u", &stack_size);

      if (stack_size > MAX_CAPACITY_STACK) {
         printf("the stack cannot be this big, the max size is 1 million\n");
      }
   } while(stack_size < 1 || stack_size > MAX_CAPACITY_STACK);

   dynamic_array* stack = array_stack_create(stack_size);

   int choice = -1;
   printf("\nYou created a stack with %u capacity\n\n", stack_size);
   printf("choose an option:\n");
   
   while(choice != 5)
   {
      printf("0.list options details\n1.pop\n2.push\n3.peek\n4.isEmpty\n5.destroy");

      switch(choice)
      {
         case 1:
               if(array_stack_pop(stack) == 0) printf("operation succeded\n");
               else printf("error, operation failed\n");
               break;
         case 2:
               u32 added_int = 0;
               printf("number to add to stack: ");
               scanf("%u", &added_int);
               if(array_stack_push(stack, added_int) == 0) printf("operation succeded\n");
               else printf("error, operation failed\n");
               break; 
         case 3:
               array_stack_peek(stack);
         case 4:
               array_stack_is_empty(stack);
         case 5:
               array_stack_destroy(stack);
               printf("Stack destroyed, operation successfull");
               break;
         default:
               printf("this is not a valid answer, try again\n");
      }
   }

   array_stack_destroy(stack);

   return 0;
}

// Data Structure based on nodes and linked list

int stack()
{
   return 0;
}

int queue()
{
   return 0;
}