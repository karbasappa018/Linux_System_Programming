/*
    Program Description:
    --------------------
    This program demonstrates the use of the open() system call
    to open an existing file from the current working directory.

    The file "Demo.txt" is opened in read and write mode using
    the O_RDWR flag.
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
    int fd = 0;

    fd = open("Demo.txt",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to allocate file\n");
    }
    else
    {
        printf("file is opened with fd :%d",fd);
    }

    close(fd);

    return 0;
}