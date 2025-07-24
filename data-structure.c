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
   while(options =! 0)
   {
      printf("Choose the Data Structure that you would like to test:\n");
      printf("1. Stack.\n");
      printf("2. Queue.\n");
      printf("3. Tree.\n");

      printf("0. Quit program.\n");

      scanf("%d", options);

      switch(options)
      {
         case 1:
               printf("==// Stack //==\n");
               printf("A stack is a data structure that works with lifo (last in first out).\n");
               printf("So you can only add(push), or remove(pop) from the top.\n");
               printf("To a stack of size 4 it will look somethign like this:\n\n");
               printf("\t\t|\t\t->\t\t|\t\t->\t\t|\t\t->\t\t|\t\t->\t\t|\t\t->\t\t|\n");
               printf("\t\t|\t\t->\t\t|\t\t->\t\t|\t\t->\t\t■\t\t->\t\t|\t\t->\t\t|\n");
               printf("\t\t|\t\t->\t\t|\t\t->\t\t■\t\t->\t\t■\t\t->\t\t■\t\t->\t\t|\n");
               printf("\t\t|\t\t->\t\t■\t\t->\t\t■\t\t->\t\t■\t\t->\t\t■\t\t->\t\t■\n\n");
               printf("First, choose the starting size of the stack.\n");
               printf("these are the possible operation:\n");
               printf("1.pop -- removers top\n2.push -- adds top\n3.Peek -- see top value\n");
               printf("4.isEmpty -- see if is empty\n5.isFull -- see if is full\n");
               break;

         case 2:
         case 3:
         case 0:
               printf("Quiting...\n");
               return 0;
         default:
               printf("This is not aa valid option, try again.\n");
               break;
      }
   }
   return 0;
}

// Data Structures using arrays

u32 stack_array(u32 stack_size)
{
   dynamic_array stack = {
      .data = malloc(stack_size* sizeof(*stack.data)), // this sizeof() is getting u32 defined in dynamic_array
      .size = 0,
      .current_capacity = stack_size,
      .max_capacity = MAX_CAPACITY,
   };

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