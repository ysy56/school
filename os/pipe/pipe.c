#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    // fd[0]:read, fd[1]:write
    int fd[2], nbytes  = 0;
    pid_t pid;
    char string[] = "1234";
    char readbuffer[80];

    if(pipe(fd)<0){
	fprintf(stderr, "error");
    }

    pid = fork();

    if(pid<0){
	perror("fork");
	return 0;
    }

    if(pid>0){// parent process
	close(fd[0]);// 부모  프로세스는 write 할꺼기에 Read FD는 닫는다.
	write(fd[1], string, (strlen(string)+1));// pipe에 메시지 보내기
	printf("Parent Process : Send \"%s\"to Child...\n", string); 
	// parent will wait for the child to complete
	wait(NULL);
	return 0;
    }
    else {// chile process
	close(fd[1]);// 자식 프로세스는 Read 할꺼기에 Write FD는 닫는다.
	nbytes = read(fd[0], readbuffer, sizeof(readbuffer));// pipe에서 메시지 읽기
	printf("Child Process : Received \"%s\"from Parent\n", readbuffer);
    }
}
