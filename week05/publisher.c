#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    mkfifo("/tmp/ex1", 0777);

    int file_descriptor = open("/tmp/ex1", O_WRONLY);
 

    char to_publish[1024];
    while (fgets(to_publish, 1024, stdin))
    {

        for (int i = 0; i < n; i++)
        {
            write(file_descriptor, to_publish, sizeof(to_publish));
         
        }
        sleep(1);
    }
    close(file_descriptor);

    return EXIT_SUCCESS;
}