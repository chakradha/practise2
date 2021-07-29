#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
//Pipe 1 //
int main()
{
    int fd;
    mkfifo("chakrififo",S_IWUSR | S_IRUSR);
    fd = open("chakrififo",O_WRONLY);
    write(fd,"DESD\n",5);
    close(fd);
}
