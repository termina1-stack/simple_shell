# Project 1 — Simple Shell
This is the second project of Operating System course

This project consists of designing a C program to serve as a shell interface that accepts user commands
and then executes each command in a separate process. Your implementation will support input and
output redirection, as well as pipes as a form of IPC between a pair of commands. Completing this project
will involve using the UNIX fork(), exec(), wait(), dup2(), and pipe() system calls and can be completed
on Linux system.

## I. Overview
A shell interface gives the user a prompt, after which the next command is entered. The example below
illustrates the prompt osh> and the user’s next command: cat prog.c. (This command displays the file
prog.c on the terminal using the UNIX cat command.)

One technique for implementing a shell interface is to have the parent process first read what the user
enters on the command line (in this case, cat prog.c) and then create a separate child process that performs
the command. Unless otherwise specified, the parent process waits for the child to exit before continuing.
However, UNIX shells typically also allow the child process to run in the background, or concurrently.
To accomplish this, we add an ampersand (&) at the end of the command.
The parent and child processes will run concurrently
The separate child process is created using the fork() system call, and the user’s command is executed
using one of the system calls in the exec() family.
