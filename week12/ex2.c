#include <stdio.h>
#include <errno.h>
#include <linux/input.h> 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
	const char* file_path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	FILE* file = fopen(file_path, "r");
    struct input_event event_struct;
	
	if (file == NULL) {
		printf("There was an error opening the file");
		return 1;
	}

    const char* RELEASED_STR = "RELEASED";
    const char* PRESSED_STR = "PRESSED";

	while (fread(&event_struct, sizeof(struct input_event), 1, file)) 
	{
		if (event_struct.type == EV_KEY) 
		{
			if (event_struct.value == 0) 
			{ 	// RELEASED
				printf("%s 0x%04x (%d) \n", RELEASED_STR, event_struct.code, event_struct.code);
				fflush(stdout);
			} 
			else if (event_struct.value == 1) 
			{ 	// PRESSED	
				printf("%s 0x%04x (%d) \n", PRESSED_STR, event_struct.code, event_struct.code);
				fflush(stdout);
			}
		}
	}

	fclose(file);
	fflush(stdout);

	return 0;
}
