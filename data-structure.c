/* data-structure.c */

#include "data-structure.h"
#include "stack/stack.h"

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
            if (stack_array_ui() == -1)
               return -1;
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


// Data Structure based on nodes and linked list

int stack()
{
   return 0;
}

int queue()
{
   return 0;
}
