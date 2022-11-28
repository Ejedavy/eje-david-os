#include <stdio.h>
#include <errno.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int KEYS = 7777;

int main() {
        const char* file_path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
        FILE *file = fopen(file_path, "r");

        struct input_event event_struct;
        
        if (file == NULL) {
                printf("There was an error opening the file\n");
                return 1;
        }
        
        int key_pressed[KEYS];
        for (int i = 0; i < KEYS; i++) { 
                key_pressed[i] = 0;
        }

        printf("The available shortcuts are: \n");
        printf("P + E: \"I passed the Exam!\"\n");
        printf("C + A + P: \"Get some cappuccino!\"\n");
        printf("E + C: \"Elegant Code!\"\n"); 
        
        while (fread(&event_struct, sizeof (struct input_event), 1, file)) 
        {
                if (event_struct.type == EV_KEY) {
                        if (event_struct.value == 0) {
                                key_pressed[event_struct.code] = 0;
                        } 
                        else if (event_struct.value == 1) {
                                key_pressed[event_struct.code] = 1;
                                if (key_pressed[25] && key_pressed[18]) { 
                                        printf("I passed the Exam!\n");
                                } 
                                else if (key_pressed[18] && key_pressed[46]) {
                                        printf("Elegant Code!\n");
                                }
                                else if (key_pressed[46] && key_pressed[30] && key_pressed[25]) {
                                        printf("Get some cappuccino!\n");
                                }
                        }
                }
        }
        fclose(file);
        fflush(stdout);

        return 0;
}
