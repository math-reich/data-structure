/* data-structure.c */

#include "data-structure.h"

// Struct and constants
const u32 MAX_CAPACITY = 1000000;

typedef struct
{
   u32* data;
   u32 size;
   u32 current_capacity;
   u32 max_capacity;
} dynamic_array;

// --- Main function ---
u32 main(int argc, char *argv[])
{
   s8 options = -1;
   while(options != 0)
   {
      printf("\nChoose the Data Structure that you would like to test:\n");
      printf("1. Stack.\n");
      printf("2. Queue.\n");
      printf("3. Tree.\n");
      printf("0. Quit program.\n");

      scanf("%hhd", &options);

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

u32 stack_array()
{
   u32 stack_size = 0;
   printf("==// Stack //==\n");
   printf("A stack is a data structure that works with lifo (last in first out).\n");
   printf("So you can only add(push), or remove(pop) from the top.\n");
   printf("To a stack of size 4 it will look somethign like this:\n\n");
   printf("\t|\t->\t|\t->\t|\t->\t|\t->\t|\t->\t|\n");
   printf("\t|\t->\t|\t->\t|\t->\t0\t->\t|\t->\t|\n");
   printf("\t|\t->\t|\t->\t0\t->\t0\t->\t0\t->\t|\n");
   printf("\t|\t->\t0\t->\t0\t->\t0\t->\t0\t->\t0\n\n");
   printf("These are the possible operation:\n\n");
   printf("1.pop    \tremove top\n2.push   \tadds top\n3.Peek   \tsee top value\n");
   printf("4.isEmpty\tsee if is empty\n5.isFull \tsee if is full\n\n");
   printf("First, choose the starting size of the stack, the amount of \"things\" that will fit inside the stack:\n");

   do {
      scanf("%u", &stack_size);

      if (stack_size > MAX_CAPACITY) {
         printf("the stack cannot be this big, the max size is 1 million");
      }
   } while(stack_size < 1 || stack_size > MAX_CAPACITY);

   // initiates the stack
   dynamic_array stack = {
      .data = malloc(stack_size* sizeof(*stack.data)), // this sizeof() is getting u32 defined in dynamic_array
      .size = 0,
      .current_capacity = stack_size,
      .max_capacity = MAX_CAPACITY,
   };

   // here implements the the functions and display to user

   free(stack.data);
   return 0;
}

// Data Structure based on nodes and linked list

u32 stack()
{
   return 0;
}

u32 queue()
{
   return 0;
}