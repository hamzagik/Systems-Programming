#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int my_system(const char *command)
{
    char *args[64]; 
    int status;

    char *token = strtok((char *)command, " ");
    int arg_count = 0;
    while (token != NULL && arg_count < 63)
    {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    pid_t pid = fork();
    if (pid < 0)
    {
        // Error in forking
        perror("fork");
        return -1; 
    }
    else if (pid == 0)
    { // Child process
        // Execute command using execvp
        execvp(args[0], args);
        perror("execvp");   
        exit(EXIT_FAILURE); 
    }
    else
    { 
        // Wait for the child process to complete
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status); 
    }
}

int main()
{
    int status = my_system("ls");
    printf("Exit status: %d\n", status);

    return 0;
}
