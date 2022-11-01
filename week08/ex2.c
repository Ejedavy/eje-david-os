#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	
	void * mem[10];
	for(int i =0; i < 10; i++){
		mem[i] = malloc(10 * 1024 * 1024);
		memset(mem[i], 0, 10 * 1024 * 1024);
		sleep(1);
	}
	
	return 0;
}

/*
	Exercise 2
	From the output the swapped in  and swapped out fields indicates that there are no
	space left to store new items of the current running program. Hence a swap space 
	which usually resides in the disk is used.

	Apparently from out program it can be seen that no swap was required to during the execution
	of the process.


	Exercise 3
	The top command shows the currently running processes, the resident memmory, shared memory and the
	virtual memory of processes. In our example we allocated 10MBs every second. Since our top command updates in 3 seconds,
	it shows 0.2 and 0.8 usage of the ex2 process and also how much memory is used by the process.
	
*/

