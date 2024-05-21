#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_TICKETS 51
#define WINNING_NUMBERS 6

int main(void)
{
    /* numbers initialization */
    int  i, temp;
    int  pickedBalls[WINNING_NUMBERS], isBallDrawn[NUMBER_OF_TICKETS];

    time_t timeNow;

    srand((unsigned)time(&timeNow));    
    memset(&isBallDrawn[0], 0, sizeof(int) * NUMBER_OF_TICKETS);

/* draw numbers */

    for(i = 0; i <  WINNING_NUMBERS ; i++)
   {
        pickedBalls[i] = rand() % NUMBER_OF_TICKETS + 1;
      
        while(1)
       {
            if(isBallDrawn[pickedBalls[i]])
            {
                pickedBalls[i] = rand() % NUMBER_OF_TICKETS + 1;
            }
            else
            {
                isBallDrawn[pickedBalls[i]] = 1;
                break;
            }
        }
   }

    putchar('\n');

/* sort numbers */
    puts(" Here are your numbers!");
    for(i= 0; i < WINNING_NUMBERS - 1 ; i++)
    {
        for(int j = i + 1; j < WINNING_NUMBERS; j++)
        {
            if(pickedBalls[i] > pickedBalls[j])
            {
                temp = pickedBalls[i];
                pickedBalls[i] = pickedBalls[j];
                pickedBalls[j] = temp;
            }
         }
     }


/* Display results */
    for(i = 0; i < WINNING_NUMBERS; i ++)
    {
        printf("%d ", pickedBalls[i]);
    }

    putchar('\n');

    return 0;
}
