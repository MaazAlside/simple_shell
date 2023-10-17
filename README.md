# simple_shell
simple_shell
# Simple Shell Project

## Background Context

This project involves the creation of a simple UNIX command interpreter. The objective is to build a shell that can interpret basic commands, handle command lines with arguments, manage the PATH, implement built-ins such as exit and env, and more. The project aims to deepen the understanding of system calls, processes, and the workings of a shell.

## Learning Objectives

- The original designer and implementer of the Unix operating system
- The first version of the UNIX shell and its designer
- The inventor of the B programming language (predecessor to C)
- Who Ken Thompson is
- How a shell works
- The concepts of pid and ppid
- Manipulation of the environment of the current process
- The difference between a function and a system call
- How to create processes
- The three prototypes of main
- How the shell uses the PATH to find programs
- Execution of another program with the execve system call
- Suspending the execution of a process until one of its children terminates
- Understanding EOF ("end-of-file")

## Requirements

- Code should be beautiful and pass the Betty style checks.
- Code should be compiled on Ubuntu 20.04 LTS using gcc with specific options.
- All files should end with a new line.
- A README.md file at the root is mandatory.
- No more than 5 functions per file.
- All header files should be include guarded.
- Use system calls only when necessary.
- No memory leaks.
- Only allowed editors: vi, vim, emacs.

## Compilation

The shell will be compiled using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

The shell should work in both interactive and non-interactive modes, providing output similar to the standard `/bin/sh`. Examples are given in the README.

## Tasks

1. **Betty would be proud**: Ensure the code passes the Betty style checks.

2. **Simple shell 0.1**: Write a UNIX command line interpreter that can execute simple commands without arguments.

3. **Simple shell 0.2**: Extend the shell to handle command lines with arguments.

4. **Simple shell 0.3**: Further enhance the shell to handle the PATH and avoid unnecessary fork calls.

5. **Simple shell 0.4**: Implement the exit built-in that exits the shell.

6. **Simple shell 1.0**: Add the env built-in to print the current environment.

7. **Simple shell 0.1.1 (Advanced)**: Write your own getline function, minimizing calls to the read system call.

8. **Simple shell 0.2.1 (Advanced)**: Handle command lines without using strtok.

9. **Simple shell 0.4.1 (Advanced)**: Handle arguments for the built-in exit.

10. **setenv, unsetenv (Advanced)**: Implement setenv and unsetenv built-in commands.

11. **cd (Advanced)**: Implement the cd built-in command, including handling the command `cd -`.

12. **; (Advanced)**: Handle the command separator `;`.

13. **&& and || (Advanced)**: Handle the shell logical operators `&&` and `||`.

14. **alias (Advanced)**: Implement the alias built-in command.

15. **Variables (Advanced)**: Handle variable replacement, including `$?` and `$$`.

16. **Comments (Advanced)**: Handle comments in the shell using `#`.

17. **File as input (Advanced)**: Allow the shell to take a file as a command-line argument, containing commands to be executed.

Feel free to check each task's respective repository on GitHub for more details and progress.