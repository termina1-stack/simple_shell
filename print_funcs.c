#include "simple_shell.h"

/**
 * print_number - Function that prints unsigned integers
 * @n: Unsigned integer
 */

void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_number_int - Function that prints integers using
 * @n: Integer value
 */

void print_number_int(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_echo - Executes built-in echo function
 * @cmd: Parsed Command
 * Return: 0 on Success, else 1
 */

int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * _putchar - Function that writes the characters to stdout
 * @c: The character to print
 * Return: character to standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints a string
 * @str: pointer to string
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
