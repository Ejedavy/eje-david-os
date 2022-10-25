#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char** s = malloc(sizeof(char*)); // Allocate memory for s dyanmically
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n", *s); // The string is what s is pointing to
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return(0);
}
