#include <stdio.h>

#include <stdlib.h>

int main(void) {
  char command[50];
  for (;;) {
    scanf("%s", command);
    system(command);
  }
}