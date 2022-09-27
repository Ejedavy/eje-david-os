#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(void) {

  pid_t pid = fork();
  if(pid == 0){
    char command[50];
    for (;;) {
    scanf("%s", command);
    system(command);
  }
  }
  wait(NULL);

  return EXIT_SUCCESS;
  
}

