#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,int argv[])
{
    pid_t id;
    printf("Parent = %d \n",getpid());
    id = fork();
    if(0 == id)
    {
        sleep(6);
        printf("CHild process\n");
     
        printf("Child PID= %d \n",getpid());
        printf("Child PPID= %d \n",getppid());

        printf("CHILD Id = %d\n",id);
    }
    else{
        printf("Parent process");
        printf("Child = %d \n",getpid());
        printf("Parent PPID= %d \n",getppid());

        printf("Parent Id = %d\n",id);
        
    }
    
}
