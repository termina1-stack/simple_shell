#include "simple_shell.h"

/**
 * command_parser - Function that passes the command recieved from stdin
 * @input: String from stdin
 * Return: Strings to be used arguments
 */

char **command_parser(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = _strtok(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}
