#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    int file_descriptor[2];
    if (pipe(file_descriptor) == -1)
        return 1;

    pid_t pid = fork();
    if (pid == -1)
        return 2;

    if (pid == 0)
    {
        close(file_descriptor[0]);
        char message[1024];
        while (fgets(message, 1024, stdin))
        {
            write(file_descriptor[1], message, sizeof(message));
            sleep(1);
        }
        close(file_descriptor[1]);
    }
    else
    {
        close(file_descriptor[1]);
        char message[1024];
        while (read(file_descriptor[0], message, sizeof(message)))
        {
            printf("%s", message);
            sleep(1);
        }
        close(file_descriptor[0]);
    }

    return EXIT_SUCCESS;
}

// pipe reference
// https://man7.org/linux/man-pages/man2/pipe.2.html