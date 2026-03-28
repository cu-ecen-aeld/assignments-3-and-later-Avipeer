#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        openlog(NULL,0,LOG_USER);//initialize logging
        //set argc as 3 because the first argument is the file name, and additioanly we want 2 variables
        // argv[0] = ./writer ,  argv[1] = writefile, argv[2] = writestr
        if(argc != 3){
                syslog(LOG_ERR,"Invalid Number of arguments: %d",argc);
                exit(EXIT_FAILURE);
        }
        int fd;//file descriptor
        int errno_state;//stores errno
        //O_WRONLY - write only, O_CREAT - creates the file 
        //0644 - file permissions, added because file couldnt be written to due to permissions
        fd = open (argv[1],  O_WRONLY | O_CREAT,0644);
        if (fd == -1){
                errno_state = errno;
                syslog(LOG_ERR,"Error opening file %s: %s",argv[1],strerror(errno_state));
                exit (EXIT_FAILURE);
        }
        ssize_t nr;
        /* write the string to 'fd' */
        nr = write(fd, argv[2], strlen (argv[2]));
        if (nr == -1){//-1 when failed to write
                errno_state = errno;
                syslog(LOG_ERR,"Write error: %s",strerror(errno_state));
                exit (EXIT_FAILURE);
        }
        syslog(LOG_DEBUG,"Writing %s to %s",argv[2],argv[1]);
        if (close(fd) == -1){
                errno_state = errno;
                syslog(LOG_ERR,"Close error: %s",strerror(errno_state));
                exit (EXIT_FAILURE);
        }
        return 0;
}
