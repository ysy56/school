#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;//프로세스ID로 변수 pid 선언
    pid = fork();//자식 프로세스 생성(부모:새로운 pid, 자식:0반환)
    if(pid>0)// 부모 프로세스
	printf("Hello\n");
    else if(pid==0){// 자식 프로세스
	printf("Hello\n");
	pid = fork();// 손자 프로세스 생성
	if(pid==0)// 손자 프로세스
	    printf("Hello\n");	    
    }
    else// pid<0 경우, 에러
	printf("error");
    printf("Hello\n");
    return 0;
}
