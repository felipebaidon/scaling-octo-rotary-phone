#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    DIR *directory;
    struct dirent *file;
    struct stat fstat;
    FILE *fh;

    /* open directory */
    directory = opendir(argv[1]);
    if(directory == NULL)
    {
        puts("Unable to access directory, try again!");
        return (1);
    }
    
    fh = fopen("filelist.txt", "w");   
    fprintf(fh,"%-5s %-20s %-10s %s\n", "Type", "Filename", "Size", "Timestamp");
    while((file=readdir(directory)) != NULL)
    {
        stat(file->d_name, &fstat);
        if(S_ISDIR(fstat.st_mode))
            fprintf(fh, "Dir ");
        else
            fprintf(fh, "File ");
        
        fprintf(fh,"%20s %10lld %s\n", file ->d_name, fstat.st_size, ctime(&fstat.st_mtime));
    }
    
   fclose(fh);
   closedir(directory);
    
   return 0;
}
