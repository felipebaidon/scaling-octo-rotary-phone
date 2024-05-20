#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_TICKETS 51
#define WINNING_NUMBERS 6

int main(void)
{
    /* numbers initialization */
    int  i;
    int tickets[NUMBER_OF_TICKETS], pickedBalls[WINNING_NUMBERS], ballDrawn[NUMBER_OF_TICKETS];

    time_t timeNow;

    srand((unsigned)time(&timeNow));    
    memset(&ballDrawn[0], 0, sizeof(int) * NUMBER_OF_TICKETS);

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
  
/* draw numbers */
    puts(" Here are your numbers!");

    for(i = 0; i <  WINNING_NUMBERS ; i++)
   {
        pickedBalls[i] = rand() % NUMBER_OF_TICKETS;
      
        while(1)
       {
            if(ballDrawn[pickedBalls[i]])
            {
                pickedBalls[i] = rand() % NUMBER_OF_TICKETS;
            }
            else
            {
                ballDrawn[pickedBalls[i]] = 1;
                break;
            }
        }

        printf( "%d ",tickets[pickedBalls[i]]);

   }

    puts("\n");

    return 0;
}
