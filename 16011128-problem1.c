#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	
	pid_t pid;
	
	pid = fork(); // fork를 통해 자식프로세스 생성
	if (pid == -1) // fork 실패시
	{
		perror("fork error");
		exit(1);
	}
	
	//getpid를 통해 프로세스 id 출력
	else if (pid > 0) // 부모
		wait(NULL); // 자식프로세스가 할 일 하도록 기다림
	else if (pid == 0) // 자식
		printf("parents pid : %d, child pid : %d\n", (int)getppid(), (int)getpid());

	return 0;
}
