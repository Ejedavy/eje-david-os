#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	
	void * mem[10];
	for(int i =0; i < 10; i++){
		mem[i] = malloc(1024 * 1024 * 1024);
		memset(mem[i], 0, 1024 * 1024 * 1024);
		sleep(1);
	}
	
	return 0;
}

/*
	From the output the swapped in  and swapped out fields indicates that there are no
	space left to store new items of the current running program. Hence a swap space 
	which usually resides in the disk is used.

	Apparently from out program it can be seen that no swap was required to during the execution
	of the process.
*/