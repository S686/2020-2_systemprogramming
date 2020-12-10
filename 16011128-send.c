#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    union sigval sigvalue;
    	
	int v[2];
	printf("input pid, DATA : ");
	scanf("%d %d", &v[0], &v[1]); //v[0] -> pid, v[1] -> value to send
	
    sigvalue.sival_int = v[1];
    //sigqueue(pid, signo, sigval_value)
    sigqueue(v[0], SIGRTMIN, sigvalue);
    pause();
    
    if (sigaction(SIGTSTP, NULL, NULL) < 0) // sigaction error
    {
        perror("sigaction error\n");
        exit(EXIT_FAILURE);
    }
    
    else
    	sigqueue(v[0], SIGRTMIN, sigvalue); 
    return 0;
}
