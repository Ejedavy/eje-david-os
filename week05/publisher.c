#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    mkfifo("tmp/ex1", 0666);

    int file_descriptor = open("tmp/ex1", O_WRONLY);
    if (file_descriptor != 0)
    {
        printf("Error opening the named pipe\n");
        return 1;
    }

    char to_publish[1024];
    while (fgets(to_publish, 1024, stdin))
    {

        for (int i = 0; i < n; i++)
        {
            if (write(file_descriptor, to_publish, sizeof(to_publish)) != 0)
            {
                printf("Error writing to the named pipe\n");
                return 1;
            }
        }
        sleep(1);
    }
    close(file_descriptor);

    return EXIT_SUCCESS;
}
