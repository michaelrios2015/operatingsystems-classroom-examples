#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// so this is just a more complex(??) version of the fork_tree simple..

// ok I think it is starting to make sense

int main(int argc, char **argv)
{
    // do I know what this is??
    pid_t pid;

    int i;

    cout << getpid() << ": Main program" << endl;

    // loop
    for (i = 0; i < 4; ++i)
    {
        // fork
        pid = fork();
        // parent
        if (pid != 0)
        {
            cout << getpid() << setw(i * 4) << ": i= " << i << ". forked child " << pid << endl;
        }
    }

    sleep(100);
    return 0;
}
