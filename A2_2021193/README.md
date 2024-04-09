Differences between system() and execvp()

system():
The system() function is a C library function that is used to execute a command by invoking the command processor.
It starts a new shell process and runs the specified command within that shell.
system() is a higher-level function compared to execvp() and provides less control over the execution environment.


execvp():
The execvp() function is another C library function used for executing a command, but it replaces the current process image with a new one.
It does not start a new shell process. Instead, it directly executes the specified command.
execvp() provides more control over the execution environment compared to system().
execvp() is suitable for executing more complex commands and provides better performance in certain scenarios.

Reasons for Choosing execvp():
execvp() offers more control over the execution environment, making it suitable for handling more complex command execution scenarios.
With execvp(), we can pass arguments to the command directly, which allows for greater flexibility.
It avoids the overhead of starting a new shell process, resulting in potentially better performance.
The execvp() function is more suited for situations where fine-grained control over the execution environment is required.

