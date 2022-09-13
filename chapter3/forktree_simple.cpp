#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    pid_t pid;

    int i;

    // just a loop
    for (i = 0; i < 3; ++i)
    {

        // so we fork this program
        pid = fork();

        // if it is a child
        if (pid == 0)
        {
            // do nothing
            wait(NULL);
        }
        // for the parent
        else
        {
            // ohhh I think I get it a bt
            cout << "Child Process. i = " << i << endl;
        }
    }
    return 0;
}