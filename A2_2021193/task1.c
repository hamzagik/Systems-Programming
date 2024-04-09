#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main() {
    char line[MAX_LINE_LENGTH];

    while (1) {
        //sub task 1
        // Read input line
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; 
        }

        // Print the line to stdout for debugging
        printf("Debug: Read line: %s", line);

        // Check if the command is "exit"
        // sub task 2
        if (strcmp(line, "exit\n") == 0) {
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        }

        // Print the line to stdout
        printf("%s", line);
    }

    return 0;
}
