/*
    Program Description:
    --------------------
    This program demonstrates the use of the open() system call
    with the O_TRUNC flag.

    The file "Ganesh.txt" is opened in read and write mode.
    If the file already exists, its contents are truncated
    (cleared) to zero length.
*/

#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd = 0;

    fd = open("Ganesh.txt",O_RDWR | O_TRUNC);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("file gets opened successfully with fd :%d",fd);
    }


    printf("\n");

    



}