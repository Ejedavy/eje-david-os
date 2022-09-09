#include <stdio.h>
#include <limits.h>

int main(void){
	int i = INT_MAX;
	unsigned short un_sh = USHRT_MAX;
	signed long si_lg = LONG_MAX;
	float fl = __FLT_MAX__;
	double dou = __DBL_MAX__;
	
	
	printf("The size of the interger is %lu\n. The value of the integer is %d\n", sizeof(i), 	i);
	printf("The size of the unsignd short is %lu\n. The value of the unsigned short is %hu\n", sizeof(un_sh), 	un_sh);
	printf("The size of the signed long is %lu\n. The value of the signed long is %li\n", sizeof(si_lg), 	si_lg);
	printf("The size of the float is %lu\n. The value of the float is %f\n", sizeof(fl), 	fl);
	printf("The size of the double is %lu\n. The value of the double is %lf\n", sizeof(dou), 	dou);
	return 0;
}
