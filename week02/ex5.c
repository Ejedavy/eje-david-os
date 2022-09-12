#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int tribonacci(int n);

int tribonacci(int n) {
    long long number1 = 0;
    long long number2 = 1;
    long long number3 = 1;
    long long current = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            current = number1;
        }
        else if(i == 1) {
            current = number2;
        }
        else if(i == 2) {
            current = number3;
        }
        else {
            current = number3 + number2 + number1;
        }
        number1 = number2;
        number2 = number3;
        number3 = current;
    }

    return current;
}

int main(int argc, char *argv[]) {
	printf("Program name %s\n", argv[0]);
   	if( argc == 3 ) {
   		for(int i = 1; i < 3; i++){printf("%d\n", tribonacci(atoi(argv[i])));}
   	}
   	else if( argc > 3 ) {
      printf("Too many arguments supplied.\n");
   	}
   	else {
      		printf("Two argument expected.\n");
   	}
   
}
