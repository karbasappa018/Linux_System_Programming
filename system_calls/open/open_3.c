/*
    Program Description:
    --------------------
    This program demonstrates the use of the open() system call
    to create and open a file from the current working directory.

    The file "Ganesh.txt" is opened in read and write mode.
    If the file does not exist, it is created using the O_CREAT flag
    with permission mode 0777.
*/

#include<stdio.h>
#include<fcntl.h>


int main()
{
    int fd = 0;

    fd = open("Ganesh.txt",O_RDWR | O_CREAT,0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("file is created and opened with fd :%d",fd);
    }


    return 0;
}