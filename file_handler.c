#include "simple_shell.h"

/**
 * treat_file - Function that parse commands and handle their execution
 * @line: Line from the file
 * @count: Keep count of errors
 * @fp: File descriptor
 * @argv: Command line arguments
 */

void treat_file(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = command_parser(line);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_stat_file(cmd, line, fp);
	else if (check_builtin_cmd(cmd) == 0)
	{
		stat = handle_builtin_cmd(cmd, stat);
		free(cmd);
	}
	else
	{
		stat = execute_cmd(cmd, line, count, argv);
		free(cmd);
	}
}

/**
 * read_file - Function that reads commands from the argument File
 * @file: File that contains the commands
 * @argv: Arguments that have been passed
 * Return: 0 on success, -1 on failure
 */

void read_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		error_file(argv, count);
		exit(127);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		treat_file(line, count, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * exit_stat_file - Exit status handler for file input
 * @line: Line from a file
 * @cmd: Parsed command
 * @fd: File Descriptor
 */

void exit_stat_file(char **cmd, char *line, FILE *fd)
{
	int status;
	int i = 0;

	if (cmd[i] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
			perror("Number not allowed");
	}
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
