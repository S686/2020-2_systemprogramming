#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	pid_t pid = fork();
	
	if (pid < -1) // fork 실패시
	{
		perror("fork error");
		exit(1);
	}
	
	else if (pid == 0) // 자식
	{
		execl("/bin/ls", "ls", NULL); //execl() 명령으로 명령 실행, 첫번째 인자는 path, 2번째 인자는 명령, 마지막 인자는 NULL
	}

	else if (pid > 0) // 부모
	{
		printf("execl () 함수 실행\n");
		wait(NULL);
		return 0;
	}

	return 0;
}
