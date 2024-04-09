#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int my_system(const char *command)
{
    char *args[64];
    int status;
    int background = 0;

    // Make a copy of the command string
    char *cmd_copy = strdup(command);
    if (cmd_copy == NULL)
    {
        perror("strdup");
        return -1;
    }

    char *token = strtok(cmd_copy, " ");
    int arg_count = 0;
    while (token != NULL && arg_count < 63)
    {
        args[arg_count++] = token;
        if (strcmp(token, "&") == 0)
        {
            background = 1;
            args[arg_count - 1] = NULL;
        }
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        free(cmd_copy);
        return -1; 
    }
    else if (pid == 0)
    { // Child process
        signal(SIGCHLD, SIG_IGN);

        // Execute command using execvp
        execvp(args[0], args);
        perror("execvp"); 
        free(cmd_copy);
        exit(EXIT_FAILURE); 
    }
    else
    { // Parent process
        if (!background)
        {
            // Wait for the child process to complete
            waitpid(pid, &status, 0);
            free(cmd_copy);
            return WEXITSTATUS(status); 
        }
        else
        {
            printf("Background process started with PID: %d\n", pid);
            free(cmd_copy);
            return 0; 
        }
    }
}

int main()
{
    int status = my_system("ls &");
    printf("Exit status: %d\n", status);

    return 0;
}
