#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid;

    /* fork a child process */

    // so is this forking this function?? and is this why it's called a fork in github
    // so it was forked... we have two of these running
    pid = fork();

    if (pid < 0)
    { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    // the child ones does this
    else if (pid == 0)
    { /* child process */
        // execute a file?? which file and do we execute and what do the arguments mean
        execlp("/bin/ls", "ls", "-l", NULL);
    }
    // the parent one does this (but only after the child is complete)
    else
    { /* parent process */
        /* parent will wait for the child to complete */

        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}
