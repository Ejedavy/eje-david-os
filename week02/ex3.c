#include <stdio.h>
#include <string.h>

int canConvert(long long toconvert, int s){
	char mystr[256];
	int len;
	sprintf(mystr, "%lld", toconvert);  
   	len = sprintf(mystr, "%lld", toconvert);
   	for (int i = 0; i < len; i++){
   		if (mystr[i]-'0'>= s){
  			printf("Cannot convert\n");
   			return 0;
   		}
   	}
   	return 1;
}

void convert(long long int x, int s, int t)
{
	if(s == 10){
	long long int base10number = x;
		char result[100];
    	int index = 0;
    	while (base10number != 0)
    	{
        	int digit = base10number % t;
        	result[index] = digit + '0';
        	base10number /= t;
        	index++;
    	}
    	result[index] = '\0';

    	for(int i = strlen(result) - 1; i >= 0; i--) {
        	printf("%c", result[i]);
    	}
    	puts("");
	
	}else{
	long long int base10number = 0;

    	long long int position = 1;
    	while (x != 0)
    	{
    	    int digit = x % 10;
    	    base10number += digit * position;
    	    position *= s;
    	    x /= 10;
    	}
    	char result[100];
    	int index = 0;
    	while (base10number != 0)
    	{
    	    int digit = base10number % t;
    	    result[index] = digit + '0';
    	    base10number /= t;
    	    index++;
    	}
	result[index] = '\0';
    	for(int i = strlen(result) - 1; i >= 0; i--) {
    	    printf("%c", result[i]);
    	}
    	puts("");
	}
}

int main()
{
    long long int x;
    int t;
    int s;

    scanf("%lld %d %d", &x, &s, &t);
    if( canConvert(x,s)){convert(x, s, t);}
}
