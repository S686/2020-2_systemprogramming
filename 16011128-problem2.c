#include <stdio.h> 
#include <unistd.h> 
#include <string.h> 
#include <signal.h> 
#include <stdlib.h>

void handler(int signo)
{
	psignal(signo, "\nReceived Signal : "); //print signal info
	sleep(2); // sleep 2 second
	exit(1); // exit program
}
int main()
{
	int i = 0;
	struct sigaction a;
	sigemptyset(&a.sa_mask); // sig act empty set
	sigaddset(&a.sa_mask, SIGQUIT); // sig act set SIGQUIT
	a.sa_flags = 0; // sig act set flags
	a.sa_handler = handler; // sig act set handler
    	
	while(1) {
		printf("Wait for signal to be received!\n");
		i++; // count
		printf("%d\n", i); // print count
		
		if ( sigaction(SIGTSTP, &a, NULL) < 0 ) { // SIGTSTP error
        		perror("SIGTSTP error");
        		exit(EXIT_FAILURE);
    		}
    	
    		if ( sigaction(SIGINT, &a, NULL) < 0 ) { // sigaction error
        		perror("SIGINT error");
        		exit(EXIT_FAILURE);
    		}
    		
		sleep(1);
	}
	return 0;
}
