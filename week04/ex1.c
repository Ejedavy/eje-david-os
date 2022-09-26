#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>

long timeInMillisecs()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return time.tv_sec * 1000 + time.tv_usec / 1000;
}

int main(void)
{
	pid_t pid1 = fork();
	long begin;
	if (pid1 != 0)
	{
		pid_t pid2 = fork();

		begin = timeInMillisecs();

		if (pid2 == 0)
			printf("Child process. ID: %d, Parent ID: %d\n", getpid(), getppid());
		else
			printf("Parent process. ID: %d, Parent ID: %d\n", getpid(), getppid());
	}
	else
	{
		begin = timeInMillisecs();
		printf("Child process. ID: %d, Parent ID: %d\n", getpid(), getppid());
	}

	long end = timeInMillisecs();

	printf("Execution time for [PID = %d]: %ldms\n\n", getpid(), end - begin);

	return EXIT_SUCCESS;
}
