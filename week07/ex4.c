#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void* func_realloc(void* source, size_t size) {	
	size_t source_size = (source == NULL ? 0 : malloc_usable_size(source));
	int to_cpy;
	if(size <= source_size){
		to_cpy = (int)size;
	}else{
		to_cpy = (int)source_size;
	}

	void * result = malloc(size);
	memcpy(result, source, to_cpy);
	free(source);
	return result;
}
int main(int argc, char** argv) {
	// write your test here 
	return 0;
}	
