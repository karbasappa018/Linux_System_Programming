/*
    Check file access permission

    1.  Accept file name and mode(read/Write/Execute).

    2.  Use access() to check permission for current process.

    3.  print "Accessible/Non Accessible" with reason.
*/

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char FileName[100]; 
    memset(FileName,'\0',sizeof(FileName));

    char mode[10];
    memset(FileName,'\0',sizeof(mode));

    printf("Enter the File name\n");
    scanf("%s",FileName);

    printf("Enter the mode(read/write/execute)\n");
    scanf("%s",mode);

    int fd = 0;
    int flag = 0;

    if(strcmp(mode,"read")==0)
    {
        flag = R_OK;
    }
    else if(strcmp(mode,"write")==0)
    {
        flag = W_OK;
    }
    else if(strcmp(mode,"execute")==0)
    {
        flag = X_OK;
    }
    else
    {
        printf("Invalid flag\n");
    }

    

    fd = access(FileName,flag);

    if(fd == -1)
    {
        printf("Error is : %s\n",strerror(errno));
        return -1;
    }
    else
    {
        printf("Accessible\n");
    }

    return 0;
    
}

/*
    Test Cases:

    B.txt file have permissions 0444.

    --------------------------------------------------

    Case : 1

    Input : Enter the file name:
            B.txt

            Enter the mode(read/write/execute):
            read

    Output : Accesible 

    ---------------------------------------------------

    Case : 2

    Input : Enter the file name:
            B.txt

            Enter the mode(read/write/execute):
            write

    Output : Error: Permission denied.


    ---------------------------------------------------




*/
