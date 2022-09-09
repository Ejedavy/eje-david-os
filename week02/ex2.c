#include <stdio.h>
#include <string.h>



int main(void){
	char to_print[256];
	char reversed_string[256];
	char buf = getchar();
	int i = 0;
	while(( buf != '.') && (buf != '\0')&& (buf != '\n')) {
		to_print[i] = buf;
		i++;
		buf = getchar();		
	}
	to_print[i] = '\0';
	

	for(int k = strlen(to_print);k >= 0; k--){
		reversed_string[strlen(to_print) - k] = to_print[k-1];
	}	
		
	printf("\"%s\"", reversed_string);

	return 0;
}
