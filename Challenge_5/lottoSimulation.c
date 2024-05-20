#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define NUMBER_OF_TICKETS 51
#define WINNING_NUMBERS 6

int main(void)
{
    /* numbers initialization */
    int  i, tickets[NUMBER_OF_TICKETS];
    

    /* fill in participants in array */
    for(i = 0; i < NUMBER_OF_TICKETS ; i++)
    {
        tickets[i] = i + 1; 
    }

   /* Print participants */
   for(i = 0; i < NUMBER_OF_TICKETS ; i++)
   {
       printf("%d\n", tickets[i]);
   
   }
   
    return 0;
}
