#include "simple_shell.h"

/**
 * check_builtin_cmd - Function that checks for built-in commands
 * @cmd: Command to be check
 * Return: 0 on success, 1 if fail
 */

int check_builtin_cmd(char **cmd)
{
	builtin shl[] = {
		{"echo", NULL},
		{"env", NULL},
		{"cd", NULL},
		{"help", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
		return (-1);
	while ((shl + i)->command)
	{
		if (_strcmp(cmd[0], (shl + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin_cmd - Function that handles predefined built in commands
 * @cmd: Array of parsed command strings
 * @st: Status of last execution
 * Return: 0 on Success, -1 on failure
 */

int handle_builtin_cmd(char **cmd, int st)
{
	builtin built_in[] = {
		{"echo", echo_bul},
		{"env", d_env},
		{"cd", change_dir},
		{"help", display_help},
		{"history", d_histo},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}
