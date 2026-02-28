/*
    Open file

    1.  Accept the filename form user and open it using open().

    2.  Print : Success message + returned file descriptor.

    3.  Handles error using perror().

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char FileName[50];
    memset(FileName, '\0', sizeof(FileName));

    int fd = 0;
    
    //  Accept the file name from user

    printf("Enter the file name\n");
    scanf("%s",FileName);

    //  Open file

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        perror("Error while opening the file :\n");
        return -1;
    }
    else
    {
        printf("File is opened successfully with fd : %d\n",fd);
    }

    close(fd);

    printf("\n");

    return 0;
}

/*
    Test Cases:

        -----------------------------------------------------------------------------------------

        Input : Ganesh.txt          Output: File is opened successfully with fd : 3


        ------------------------------------------------------------------------------------------


        Input : Demo.txt            Output:    Error while opening the file :
                                               No such file or directory   
                                               
        ------------------------------------------------------------------------------------------

*/