#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
    
    pid_t id,ppid;
    id = getpid();
    ppid = getppid();

    printf("PID = %d\n",id);
    printf("PPID = %d\n",ppid);
    return 0;
    
}