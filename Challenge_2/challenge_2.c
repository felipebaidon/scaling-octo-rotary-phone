#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE  32

void inputString(void)
{
    int i = 0, x = 0;
    char *name = (char*) malloc(sizeof(char)*(BUFFER_SIZE + 1));
    char *buffer = (char*) malloc(sizeof(char)*(BUFFER_SIZE + 1));
    char *last = " passed the challenge ";

    while((name[i++] = getchar()) != '\n' ){}

    name[i] = '\0';
    
    for( x=0; x < i; x++)
    {
     buffer[x] = name[x];
    }

    printf("\n----%s\n",&name[0]);
    printf("\n----%s\n",&buffer[0]);

    for(x=0; x < strlen(last);x++)
    {
        buffer[x+i-1]= last[x];
    } 
  
    printf("\n-----%s\n",&buffer[0]);

}



int main(void)
{
    inputString();
   
    return 0;

}
