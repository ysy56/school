#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    pid_t pid;
    pid = fork();
    if(pid<0){
	fprintf(stderr,"fork failed");
	return 1;
    }	
    else if(pid>0){
	printf("hello\n");
	//wait(NULL);
    }
    else{
	printf("hello\n");
    }
    return 0;
};
