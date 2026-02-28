/*
     Display Complete File Information
     
     1. Accept file name and display file metadata using stat():
     2. Size, inode, permissions, hard links, owner uid/gid, file type, last access/modify time.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>

int main(int argc, int argv[])
{
    int fd = 0;
    int iRet = 0;
    mode_t mode;
    char FileName[50] = {'\0'};
    memset(FileName,'\0',sizeof(FileName));

    printf("Enter the File Name:\n");
    scanf("%s",FileName);

    

    fd = open(FileName,O_RDONLY | O_CREAT,0444);

    if(fd == -1)
    {
        perror("Error while opening file:");
        return -1;
    }
    else
    {
        printf("File is opened successfully with fd:%d\n",fd);

    }

    struct stat sobj;

    iRet = stat(FileName,&sobj);

    printf("Size :%ld\n",sobj.st_size);
    printf("inode number:%ld\n",sobj.st_ino);
    printf("Hard links:%ld\n",sobj.st_nlink);
    printf("Owner UID:%d\n",sobj.st_uid);
    printf("Owner GID:%d\n",sobj.st_gid);
    printf("File type and mode: ");
    
        
    if((sobj.st_mode & S_IFMT)== S_IFREG)
    {
        printf("Regular File\n");
    }
    else if((sobj.st_mode & S_IFMT)== S_IFDIR)
    {
        printf("Directory file\n");
    }
    else if((sobj.st_mode & S_IFMT)==S_IFBLK)
    {
        printf("Block device\n");
    }
    else if((sobj.st_mode & S_IFMT)==S_IFCHR)
    {
        printf("character device\n");
    }
    else if((sobj.st_mode & S_IFMT)==S_IFLNK)
    {
        printf("Symbolic link\n");
    }
    else if((sobj.st_mode & S_IFMT)==S_IFSOCK)
    {
        printf("Socket\n");
    }

    mode = sobj.st_mode;

    printf("Owner permissions\n");
    printf( (mode & S_IRUSR) ? "r" : "-" );
    printf( (mode & S_IWUSR) ? "w" : "-" );
    printf( (mode & S_IXUSR) ? "x" : "-" );
    printf("\n");

    printf("Group Permissions\n");
    printf( (mode & S_IRGRP) ? "r" : "-" );
    printf( (mode & S_IWGRP) ? "w" : "-" );
    printf( (mode & S_IXGRP) ? "x" : "-" );
    printf("\n");

    printf("Others's permissions\n");
    printf( (mode & S_IROTH) ? "r" : "-" );
    printf( (mode & S_IWOTH) ? "w" : "-" );
    printf( (mode & S_IXOTH) ? "x" : "-" );
    printf("\n");

    printf("Last status change:%s",ctime(&sobj.st_ctime));
    printf("Last file access:%s",ctime(&sobj.st_atime));
    printf("Last file modification:%s",ctime(&sobj.st_mtime));


    return 0;
}

/*

    ------------------------------------------------------------------------------------

    Input : Demo.txt


    Output :    File is opened successfully with fd:3
                Size :19
                inode number:19185305
                Hard links:1
                Owner UID:1000
                Owner GID:1000
                File type and mode: Regular File
                Owner permissions
                rwx
                Group Permissions
                rwx
                Others's permissions
                r-x
                Last status change:Mon Feb 16 18:52:58 2026
                Last file access:Sat Feb 21 21:52:55 2026
                Last file modification:Mon Feb 16 18:52:58 2026

    -------------------------------------------------------------------------------------

*/