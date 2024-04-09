#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 80
// max number of arguments
#define MAX_ARGS 10 

int main() {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        // sub task 1
        // Read input line
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; 
        }

        // Check if the command is "exit"
        if (strcmp(line, "exit\n") == 0) {
            printf("Exiting...\n");
            break;
        }

        //sub task 4
        char *token = strtok(line, " \n");
        int arg_count = 0;
        while (token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " \n");
        }
        args[arg_count] = NULL;

        execvp(args[0], args);

        perror("execvp");
    }

    return 0;
}
