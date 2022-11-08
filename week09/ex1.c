#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX_PAGES 1000
#define AGE_SIZE 32

unsigned int number_of_page_frames;
unsigned int age_record[MAX_PAGES]; 
unsigned int *page_table;
unsigned int last_swap_index;
int hits, misses;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr,
                "Please enter the number of frames.\n");
        return 1;
    }

    FILE *input = fopen("input.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Could not open input.txt\n");
        return 2;
    }

    number_of_page_frames = atoi(argv[1]);
    page_table = (unsigned int *)calloc(number_of_page_frames, sizeof(int));

    for (int page; fscanf(input, "%d", &page) == 1;) {
        int hit_flag = 0;
        for (int i = 0; i < number_of_page_frames; i++) {
            if (page == page_table[i]) {
                hits++;
                hit_flag = 1;
                break;
            }
        }

        if (hit_flag == 0) {
            misses++;
            unsigned int lowest_age = UINT_MAX;
            int index_to_swap = 0;
            for (int i = 0; i < number_of_page_frames; i++) {
                unsigned int temp_lowest_age = age_record[page_table[i]];
                if (temp_lowest_age <= lowest_age)
                    lowest_age = temp_lowest_age, index_to_swap = i;
            }
            page_table[index_to_swap] = page;
            age_record[page] = 0;
        }

        for (int i = 0; i < MAX_PAGES; i++)
            age_record[i] >>= 1;
        age_record[page] |= 1 << (AGE_SIZE - 1);
    }

    printf("Total pages hit:\t%d\n", hits);
    printf("Total pages missed:\t%d\n", misses);
    printf("Hit ratio:\t\t%.3f%\n", 100.0 * hits / misses);

    return 0;
}





