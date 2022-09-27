#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{

    char command[1000];
    pid_t parent_process = getpid();
    pid_t fg_command;
    while (fgets(command, 1000, stdin))
    {
        if (strcmp(command, "exit\n") == 0)
            break;
        if (getpid() == parent_process)
        {
            if (command[strlen(command) - 2] != '&')
            {
                fg_command = fork();
            }
            else
            {
                fork();
            }
            if (getpid() != parent_process)
            {
                int err = system(command);
                if(err){
                    printf("Error executing command");
                }
                return EXIT_SUCCESS;
            }
        }
        if (command[strlen(command) - 2] != '&' && getpid() == parent_process)
        {
            waitpid(fg_command, NULL, 0);
        }
    }

    return EXIT_SUCCESS;
}