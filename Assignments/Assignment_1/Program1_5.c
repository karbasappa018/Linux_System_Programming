/*
    Read N Bytes From File

    1. Accept file name and number of bytes N.
    2. Read exactly N bytes using read() and print on console.
    3. If file contains less than N, print only available bytes.

*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char FileName[20];
    memset(FileName,'\0',sizeof(FileName));

    char Buffer[50];
    memset(Buffer,'\0',sizeof(Buffer));

    printf("Enter the file name:");
    scanf("%s",FileName);

    int fd = 0;
    ssize_t iRet = 0;     // Also we can use int datatype

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        perror("Error: Unable to open file\n""Reason:");
        return -1;
    }
    else
    {
        printf("File is opened successfully with fd: %d\n",fd);
    }

    iRet = read(fd,Buffer,20);

    if(iRet== -1)
    {
        perror("Error: Unable to read the data\n""Reason:");
        return -1;
    }
    else
    {
        printf("%ld bytes of data read successfully\n",iRet);
        printf("Data from the file :%s",Buffer);
    }

    printf("\n");


    return 0;
}

/*

    Test Cases:

    ----------------------------------------------------------------------------------------------

    Input : test.txt                Output: Error: Unable to open file
                                            Reason:: No such file or directory
                                            

    ----------------------------------------------------------------------------------------------



    Input : Demo.txt                Output: File is opened successfully with fd: 3
                                            19 bytes of data read successfully
                                            Data from the file : India is my country

    -----------------------------------------------------------------------------------------------


    Input : A.txt                   Output: File is opened successfully with fd: 3
                                            20 bytes of data read successfully
                                            Data from the file :aaaaaaaaaaaaaabbbbbb
 
    -----------------------------------------------------------------------------------------------


*/