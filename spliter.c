#include "simple_shell.h"

/**
 * spliter - Function that separates command received from stdin using ;
 * @input: String input from stdin
 * Return: Strings input to be used as commands
 */

char **spliter(char *input)
{
	char **cmds;
	char *cmd;
	int i;
	int buffsize = BUFFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * buffsize);
	if (!cmds)
	{
		free(cmds);
		perror("Error shell hsh");
		return (NULL);
	}
	cmd = _strtok(input, ";&");
	for (i = 0; cmd; i++)
	{
		cmds[i] = cmd;
		cmd = _strtok(NULL, ";&");
	}
	cmds[i] = NULL;

	return (cmds);
}
