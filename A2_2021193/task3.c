#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main() {
    char line[MAX_LINE_LENGTH];

    while (1) {
        // Read input line
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; 
        }

        if (strcmp(line, "exit\n") == 0) {
            printf("Exiting...\n");
            break;
        }

        // sub task 3
        // Execute arbitrary commands using system()
        printf("Executing: %s", line);
        system(line);
    }

    return 0;
}
