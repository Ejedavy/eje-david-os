#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

// 

int main()
{
	int *data[10];


	size_t size = 0;
	struct rusage memory_usage;

	for(int i=0; i<10; i++)
	{
		size = 10 * 1024 * 1024;
		data[i] = (int *) malloc(size);

		memset(data[i], 0, size);
		
		// Gets all memory used by the calling process including the threads
		getrusage(RUSAGE_SELF, &memory_usage);
		
		printf("Memory usage: %ld\n", memory_usage.ru_maxres);
		
		sleep(1);
	}

    for(int i = 0; i < 10; i++)
	    free(data[i]);
	
	return 0;
}