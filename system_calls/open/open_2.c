/*
    Program Description:
    --------------------
    This program demonstrates the use of the open() system call
    to open a file from the current working directory.

    Since the file "Ganesh.txt" is not present and the O_CREAT
    flag is not used, the open() system call fails and returns -1.
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
    int fd = 0;

    fd = open("Ganesh.txt",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("file is opened with fd :%d",fd);
    }

    close(fd);

    return 0;
}