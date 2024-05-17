#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *directory;
    struct dirent *file;
    struct stat fstat;

    /* open directory */
    directory = opendir(argv[1]);
    if(directory == NULL)
    {
        puts("Unable to access directory, try again!");
        return (1);
    }

    printf("%-5s %-20s %-10s %s\n", "Type", "Filename", "Size", "Timestamp");
    while((file=readdir(directory)) != NULL)
    {
        stat(file->d_name, &fstat);
        if(S_ISDIR(fstat.st_mode))
            printf( "Dir ");
        else
            printf( "File ");
        
        printf("%20s %10lld %ld\n", file ->d_name, fstat.st_size, fstat.st_mtime);
    }
    
   closedir(directory);
    
   return 0;
}
