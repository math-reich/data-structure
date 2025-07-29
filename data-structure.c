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
            if (stack_array() == -1)
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

int stack_array()
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
         while (getchar() != '\n');
         valid_option = false;
      }
   }

   // creates stack and checks if it is allocated in memory
   dynamic_array* stack = array_stack_create(stack_size);
   if (stack == NULL) return -1;

   // stack possible operations
   int choice = -1;
   printf("\nYou created a stack with %u capacity\n\n", stack_size);
   printf("choose an option:\n");
   printf("0.list options details\n1.pop\n2.push\n3.peek\n4.isEmpty\n5.destroy");
   
   while(choice != 5)
   {
      scanf("O ERRO ESTAVA AQUI, FALTOU PEGAR VALOR DE CHOICE");
      switch(choice)
      {
         case 0:
               print_possible_options();
               break;
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
               break;
         case 4:
               if(array_stack_is_empty(stack)) printf("Stack is empty!");
               break;
         case 5:
               array_stack_destroy(stack);
               printf("Stack destroyed, operation successfull");
               break;
         default:
               printf("this is not a valid answer, try again\n");
               break;
      }
   }

   // not supposed to get here withou destroying stack, but for containment
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
