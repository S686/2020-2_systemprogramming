#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "FIFO_FD"
#define  FIFO_FILE   "/tmp/fifo"
#define  BUFF_SIZE   1024

int main( void)
{
    int   num = 0;
    int   fd;
    char  buff[BUFF_SIZE];

    if(mkfifo(FIFO_FILE, 0666) == -1) //mkfifo error
    {
        perror( "mkfifo() failed\n");
        return -1;
    }

    if (( fd = open( FIFO_FILE, O_RDWR)) == -1) // fd open error
    {
        perror( "open() failed\n");
        return -2;
    }
    printf("FD=%d\n", fd);

    while(1)
    {
        memset( buff, 0x00, BUFF_SIZE);
        read( fd, buff, BUFF_SIZE);
        num = atoi(buff) + 1;
        printf( "%d: \n", num);
    }
    close(fd);
    return 0;
}
