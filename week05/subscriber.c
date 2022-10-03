#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    mkfifo("tmp/ex1", 0666);

    int file_descriptor = open("tmp/ex1", O_RDONLY);
    if (file_descriptor != 0)
    {
        printf("Error opening the named pipe\n");
        return 1;
    }

    char received_message[1024];
    while (read(file_descriptor, received_message, sizeof(received_message)))
    {
        printf("%s", received_message);
        sleep(1);
    }
    close(file_descriptor);

    return EXIT_SUCCESS;
}