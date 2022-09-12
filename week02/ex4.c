#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count(char *input, char c);
void countAll(char *input);

int count(char *input, char c) {
    
    int frequency = 0;

    for(int i = 0; i < strlen(input); i++) {
        if(tolower(input[i]) == tolower(c)) {
            frequency++;
        }
    }

    return frequency;
}

void countAll(char *input) {

    for(int i = 0; i < strlen(input) - 1; i++) {
        if(input[i] == '*') {
            continue;
        }
        printf("%c: ", input[i]);
        int frequency = 1;
        for(int j = i + 1; j < strlen(input) - 1; j++) {
            if(tolower(input[i]) == tolower(input[j])) {
                input[j] = '*';
                frequency++;
            }
        }
        printf("%d ", frequency);
    }

}

int main() {

    printf("Please enter the word: ");
    char text[256];

    fgets(text, sizeof(text), stdin);

    printf("Enter the character: ");
    char c;

    scanf("%c", &c);

    int result = count(text, c);

    printf("%d\n", result);
    
    printf("For all letters in the text %s\n", text);

    countAll(text);

}
