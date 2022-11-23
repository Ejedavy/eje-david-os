#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	DIR* root;
	root = opendir("/");

	struct dirent* current;

	for(; (current = readdir(root)) != NULL; ) {
		printf("-> %s\n", current->d_name);
	}
}
