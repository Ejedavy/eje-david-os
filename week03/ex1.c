#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(const int * const p){
	for(int i = 0; i <5; i++){
		int *value = (int *)(p+i);
		*value = 2022 - *(p+i);
	}
}



int main(){
	const int x = 10;
	const int *q = &x;
	const int* const p = (int *)malloc(5 * sizeof(int));
	
	for(int i = 0; i < 5; i++) {
		int *value = (int *)(p+i);
		*value = x;
	}
		
	for (int i = 0; i < 5; i++){
		printf("%p is the address of cell %d and the value is %d\n", (p+i), (i+1), *(p+i));
	}
	
	
	printf("Enter the ages of the students:\n");
	for(int i = 0; i < 5; i++){
		int *value = (int *)(p+i);
		scanf("%d", value);
	}
	
	for (int i = 0; i < 5; i++){
		printf("Ages %d is %d after assignment\n", (i+1), *(p+i));
	}
	
	foo(p);
	
	for (int i = 0; i < 5; i++){
		printf("Birth year %d is %d\n", (i+1), *(p+i));
	}
	
	
	
	free((int *)p);
	return 0;
}
