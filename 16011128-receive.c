#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signo, siginfo_t *si)
{
    if(si->si_code == SI_QUEUE) // si_code == SI_QUEUE
    {
		// print data
        printf("User RTS signal : %d\n", si->si_pid); // print pid
        printf("Sig Number : %d\n",     si->si_signo); // print signo
        printf("User DATA : %d\n",    si->si_value.sival_int); // print sigval
        psignal(signo, "\nReceived Signal : "); //print signal info
        getchar();
    }
    else
    {
        // if send unix signal
        printf("Not realtime signal %d\n", signo); 
        psignal(signo, "\nReceived Signal : "); //print signal info
    }
}

int main()
{
    struct sigaction a;

    printf("pid = %d\n", getpid());
	
	/* register realtime signal */
    sigemptyset(&a.sa_mask);
    a.sa_flags     = SA_SIGINFO;
    a.sa_sigaction = handler; 

    // handler
    
    if (sigaction(SIGRTMIN, &a, 0) == 1) // sigaction error
    {
        perror("sigaction error\n");
        exit(EXIT_FAILURE);
    }
    
    while(1)
        sleep(1);  
        
    return 0;
}   
