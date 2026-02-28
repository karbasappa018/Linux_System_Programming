/*
    Open file in given mode

    1.  Accept the filename and mode (R, W, RW, A) from user.

    2.  Convert mode to flags(O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT ).

    3.  Open file accordingly and display fd.

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main()
{
    char FileName[50];
    memset(FileName,'\0', sizeof(FileName));

    char mode[10];
    memset(mode,'\0', sizeof(mode));

    int fd = 0;
    int flag = 0;

    printf("Enter the file name\n");
    scanf("%s",FileName);

    printf("Enter the mode (R, W, RW, A):\n");
    scanf("%s",mode);

    if(strcmp(mode,"R")==0)
    {
        flag = O_RDONLY;
    }
    else if(strcmp(mode,"W")==0)
    {
        flag = O_WRONLY;
    }
    else if(strcmp(mode,"RW")==0)
    {
        flag = O_RDWR;
    }
    else if(strcmp(mode, "A")==0)
    {
        flag = O_APPEND | O_CREAT;
    }
    else
    {
        printf("Invalid mode");
        return -1;
    }

    
    fd = open(FileName, flag, 0777);
   

    if(fd == -1)
    {
        printf("Error is : %s\n",strerror(errno));
        return -1;
    }
    else
    {
        printf("file is opened successfully with fd : %d\n",fd);   
    }

    close(fd);

    return 0;

}

/*
    Test Cases:

    B.txt file have permissions 0444.

    --------------------------------------------------

    Case : 1

    Input : Enter the file name:
            B.txt

            Enter the mode(R,W,RW,A):
            R

    Output : Accesible 

    ---------------------------------------------------

    Case : 2

    Input : Enter the file name:
            B.txt

            Enter the mode(R,W,RW,A):
            W

    Output : Error: Permission denied.


    ---------------------------------------------------




*/
