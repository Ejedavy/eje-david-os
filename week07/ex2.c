#include <stdio.h>
#include <stdlib.h>


int main(){
	int n;
	scanf("%d", &n);
	int *p = (int *)malloc(n*sizeof(int));

	for(int i = 0; i < n; i++){
		*(p+i) = i;
	}

	for(int i = 0; i < n; i++){
		printf("%d\n",*(p+i));
	}

	free(p);
	return 0;
}