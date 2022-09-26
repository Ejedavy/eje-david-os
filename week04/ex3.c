#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("Program name %s\n", argv[0]);
   	if (argc != 2){
   		printf("You need to pass valid arguments");
   	}else{
   		int n = atoi(argv[1]);
   		for(int i = 0; i < n; i++){
   			int pid = fork();
   			sleep(5);
   		}
   	}
   	return 0;

}