#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 2048
#define MAX_DATA 1024
#define MAX_LENGTH 63
#define MAX_FILES 256
#define MAX_SUB 8

struct Directory;
struct File;

typedef struct Directory Directory;
typedef struct File File;

struct File {
        int id;
        char name[MAX_LENGTH];
        int size;
        char data[MAX_DATA];

        struct Directory* directory; // The parent directory
};

struct Directory {
        File* files[MAX_FILES];
        Directory* directories[MAX_SUB];
        int nf;
        int nd;
        char path[MAX_PATH];
};

// Operations on files
void add_to_file(File* file,
                 const char* content);
void append_to_file(File* file,
                    const char* content);
void pwd_file(File* file);

// Operations on directories
void add_file(File* file, Directory* dir);
void add_dir(Directory* dir1, Directory* dir2);

// Helper functions
void show_dir(Directory* dir);
void show_file(File* file);
void show_file_detailed(File* file);

int main() {
        char content1[] = "int printf(const char* format, ...);";
        char content2[] = "int main(){printf('Hello World');}";
        char content3[] = "//This is a comment in C language";
        char content4[] = "Bourne Again Shell!";

        Directory root, home, bin;
        root.nf = 0;
	root.nd = 0;
	strcpy(root.path, "/");

	home.nf = 0;
	home.nd = 0;
	strcpy(home.path, "/home");

	bin.nf = 0;
	bin.nd = 0;
	strcpy(bin.path, "/bin");

        // Add directories
        add_dir(&home, &root);
        add_dir(&bin, &root);

        File bash, ex31, ex32;

	bash.id = 1;
	strcpy(bash.name, "bash");
	bash.size = 0;

	ex31.id = 2;
	strcpy(ex31.name, "ex3_1.c");
	strcpy(ex31.data, content1);
	ex31.size = 1;

	ex32.id = 3;
	strcpy(ex32.name, "ex3_2.c");
	strcpy(ex32.data, content2);
	ex32.size = 1;

	// Add files to directories
        add_file(&bash, &bin);
       	add_file(&ex31, &home);
        add_file(&ex32, &home);

	// Add/Append content to files 
        add_to_file(&bash, content3);
        append_to_file(&ex31, content4);

        show_dir(&root);
        show_file_detailed(&bash);
        show_file_detailed(&ex31);
        show_file_detailed(&ex32);

        pwd_file(&bash);
        pwd_file(&ex31);
        pwd_file(&ex32);

        return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory* dir) {
        printf("\nDIRECTORY\n");
        printf(" path: %s\n", dir->path);
        printf(" files:\n");
        printf("    [ ");
        for (int i = 0; i < dir->nf; i++) {
                show_file(dir->files[i]);
        }
        printf("]\n");
        printf(" directories:\n");
        printf("    { ");

        for (int i = 0; i < dir->nd; i++) {
                show_dir(dir->directories[i]);
        }
        printf("}\n");
}

// Prints the name of the File file
void show_file(File* file) {
        printf("%s ", file->name);
}

// Shows details of the File file
void show_file_detailed(File* file) {
        printf("\nFILE\n");
        printf(" id: %d\n", file->id);
        printf(" name: %s\n", file->name);
        printf(" size: %d\n", file->size);
        printf(" data:\n");
        printf("    [ %s ]\n", file->data);
}

// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(struct File* file,
                 const char* content) {
        strcpy(file->data, content);
}

void append_to_file(struct File* file,
                    const char* content) {
        strcat(file->data, content);
}

// Prints the path of the File file
void pwd_file(File* file) {
        // Example: the path for bash file is /bin/bash
        printf("%s/%s\n", file->directory->path, file->name);
}

// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File* file, Directory* dir) {
        dir->files[dir->nf] = file;
        dir->nf = dir->nf + 1;

	file->directory = dir;
}

// Adds the directoriesectory dir1 to the directory dir2
void add_dir(Directory* dir1, Directory* dir2) {
        if (dir1 && dir2) {
                dir2->directories[dir2->nd] = dir1;
                dir2->nd++;
        }
}
