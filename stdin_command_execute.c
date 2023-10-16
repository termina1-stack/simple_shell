#include "simple_shell.h"

/**
 * execute_cmd - Function that executes commands found in predefined path
 * @cmd: Array of command
 * @input: Input received from user
 * @c: Shell execution time case of command not found
 * @argv: Arguments before program starts
 * Return: 1 if case Command is Null, if -1 wrong command else 0 if command
 * is executed
 */

int execute_cmd(char **cmd, char *input, int c, char **argv)
{
	int wstatus;
	pid_t ppid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	ppid = fork();
	if (ppid == -1)
	{
		perror("Error: Parent Forking");
		return (-1);
	}
	if (ppid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], c, argv);
			free_all(cmd, input);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			return (0);
		else if (WEXITSTATUS(wstatus) == 2)
			return (2);
		else if (WEXITSTATUS(wstatus) == 127)
			return (127);
	}
	return (127);
}

/**
 * signal_to_handle - Function that configures ^C not to terminate the shell
 * @sig: Signal from user
 */

void signal_to_handle(int sig)
{
	if (sig == SIGINT)
		PRINT("\n$ ");
}
