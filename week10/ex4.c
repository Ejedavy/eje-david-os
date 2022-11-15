#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

struct file_inode {
    int inode;
    char filename[256];
};

int main(int argc, char * argv[]) {
    struct file_inode directory_inodes[1024];
    directory_inodes[0].inode = 0;
    DIR * source;
    struct dirent * parent;
    struct stat filestat;
    char filepath[512];

    source = opendir("tmp");
    printf("File -- Hard Links\n");
    int number_of_inodes = 0;
    while ((parent = readdir(source)) != NULL) {
        if (parent -> d_type != 8) {
            continue;
        }
        int result = snprintf(filepath, sizeof(filepath), "tmp/%s", parent -> d_name);
        if (result >= 512 || result < 0) {
            printf("ERROR: write to filepath failed");
            return (1);
        }
        stat(filepath, & filestat);
        if (filestat.st_nlink >= 2) {
            directory_inodes[number_of_inodes].inode = filestat.st_ino;
            strcpy(directory_inodes[number_of_inodes].filename, parent -> d_name);
            directory_inodes[number_of_inodes + 1].inode = 0;
            number_of_inodes++;
        }
    }

    int primary_inode = 0;
    while (directory_inodes[primary_inode].inode != 0) {
        printf("%s -- ", directory_inodes[primary_inode].filename);
        int inode = directory_inodes[primary_inode].inode;
        int secondary_inode = 0;
        int printed_count = 0;
        while (directory_inodes[secondary_inode].inode != 0) {
            if (directory_inodes[secondary_inode].inode == inode) {
                if (printed_count != 0) {
                    printf(", ");
                }
                printed_count++;
                printf("%s", directory_inodes[secondary_inode].filename);
            }
            secondary_inode++;
        }
        primary_inode++;
        printf("\n");
    }

    closedir(source);
    free(parent);

    return 0;
}