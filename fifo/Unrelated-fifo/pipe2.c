#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#define SIZE 10
//pipe 2//
int main()
{
    int fd;
    unsigned char buff[SIZE];
    fd = open("chakrififo",O_RDONLY);
    read(fd,buff,5);
    printf("Pipe2 got the data from the pipe1  is %s\n",buff);
    close(fd);
}
