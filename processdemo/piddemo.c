#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
    
    pid_t id;
    id = getpid();

    printf("PID = %d\n",id);
    return 0;
    
}