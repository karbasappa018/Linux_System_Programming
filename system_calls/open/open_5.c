/*
    Program Description:
    --------------------
    This program demonstrates the use of open() and close()
    system calls with the O_TRUNC flag.

    The file "Demo.txt" is opened in read and write mode.
    If the file exists, its contents are truncated to zero length.
    After the operation, the file descriptor is closed using close().
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;

    fd = open("Demo.txt",O_RDWR | O_TRUNC);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("file gets opened successfully with fd :%d",fd);
    }

    close(fd);

    printf("\n");

}