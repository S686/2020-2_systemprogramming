/* fifo-writer.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define  FIFO_FILE   "/tmp/fifo"

int main( void)
{
    int   fd;
    int num = 1;

    if ( -1 == ( fd = open( FIFO_FILE, O_WRONLY)))
    {
        perror( "open() failed\n");
        return -1;
    }
    printf("FD=%d\n", fd);

	while(1 && num < 100){
		printf("num = %d\n", num);
    	write(fd, num, sizeof(int));
    	num++;
    	sleep(1);
    }
    close(fd);
    return 0;
}
