#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>

struct Thread
{
    int id;
    int i;
    char message[256];
};

void * thread_function_routine(void *args)
{
    struct Thread* runningThread = (struct Thread*) args;

    printf("Thread with id %d outputs %s\n", runningThread->id, runningThread->message);

    return NULL;

}

int main()
{
    int n;
    scanf("%d", &n);

    struct Thread threads[n];

    for (int i = 0; i < n; i++)
    {
        struct Thread thread;

        thread.i = i;
        thread.id = i + 1;
        char partial_message[400] = "Hello from thread ";
        char number[99];
        sprintf(number, "%d", i); // Convert i to a number
        strcat(partial_message, number);
        strcpy(thread.message, partial_message);

        threads[i] = thread;
    }

    pthread_t pthreads[n];

    for (int i = 0; i < n; i++)
    {
        if (pthread_create(&pthreads[i], NULL, &thread_function_routine, &threads[i]) != 0)
        {
            printf("Thread Creation Failed");
            return 1;
        }
        
        printf("Thread %d is created.\n", i);
        pthread_join(pthreads[i], NULL);
    }

    return 0;
}
