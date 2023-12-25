#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void creatingdirectoryandchangingpath(char *newdir)
{
    struct stat st;
    if (stat(newdir, &st) == 0)
    {
        printf("Error: Directory already exists\n");
        exit(1);
    }
    int c;
    c = mkdir(newdir, 0777);
    if (!c)
    {
        char bf[1024];
        if (getcwd(bf, 1024) != NULL)
        {
            printf("%s is created in %s\n", newdir, bf);
        }
    }
    else
    {
        printf("Error\n");
        exit(1);
    }
    chdir(newdir);
    char buffer[1024];
    if (getcwd(buffer, 1024) == NULL)
    {
        printf("Getting current working directory failed");
        exit(1);
    }
    else
    {
        printf("Directory is changed to %s\n", buffer);
    }
}
void creatingdirectoryandchangingpath2(char *newdir)
{

    int c;
    c = mkdir(newdir, 0777);
    if (!c)
    {
        // printf("Directory created successfully\n");
    }
    else
    {
        printf("Error\n");
        exit(1);
    }
    chdir(newdir);
    char buffer[1024];
    if (getcwd(buffer, 1024) == NULL)
    {
        // printf("Getting current working directory failed");
        exit(1);
    }
}
void creatingdirectoryandchangingpath3(char *newdir)
{
    struct stat st;
    if (stat(newdir, &st) == 0)
    {
        printf("Error: Directory already exists\n");
        exit(1);
    }
    int c;
    c = mkdir(newdir, 0777);
    if (!c)
    {
        // printf("Directory created successfully\n");
    }
    else
    {
        printf("Error\n");
        exit(1);
    }
    chdir(newdir);
    char buffer[1024];
    if (getcwd(buffer, 1024) == NULL)
    {
        printf("Getting current working directory failed");
        exit(1);
    }
}

void removedirectory(char *olddir)
{
    int remdir;
    remdir = rmdir(olddir);
    if (remdir == -1)
    {
        printf("Removal of directory failed");
        exit(1);
    }
    else
    {
        return;
    }
}
int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Input Format {dir} {-option} {dir_name}");
        exit(1);
    }
    else if (argc == 2)
    {
        creatingdirectoryandchangingpath3(argv[1]);
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "-r") == 0)
        {
            struct stat st;
            if (stat(argv[2], &st) == 0)
            {
                removedirectory(argv[2]);
                creatingdirectoryandchangingpath2(argv[2]);
            }
            else
            {
                creatingdirectoryandchangingpath2(argv[2]);
            }
        }
        else if (strcmp(argv[1], "-v") == 0)
        {
            creatingdirectoryandchangingpath(argv[2]);
        }
        else
        {
            printf("Error: The command is incorrect\n");
        }
    }

    // currentworkingdirectory();
    // changingpathtodirectory(argv[2]);

    return 0;
}
