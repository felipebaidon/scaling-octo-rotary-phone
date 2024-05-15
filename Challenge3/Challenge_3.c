#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEOFARRAY 10
#define BUFFERSIZE 32

int main(void)
{
    char *arayPtr[SIZEOFARRAY];
    char buffer[BUFFERSIZE];
    int i;

    for(i = 0; i < SIZEOFARRAY; i++)
    {
        printf(" Enter string #%d:", i + 1 );
        fgets(buffer, BUFFERSIZE , stdin);
        
        
        arayPtr[i] = (char*)malloc(strlen(buffer)+1);
        if(arayPtr[i] == NULL)
        {
            puts(" Memory allocation failed!");
            exit(1);
        }

        strcpy(arayPtr[i],buffer);
    }

   for(i=0; i< SIZEOFARRAY; i++)
   {
      printf("%s",arayPtr[i]);
   }
    
return 0;

}
