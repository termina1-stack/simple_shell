#include "simple_shell.h"

/**
 * create_env - Function that creates an array of Enviroment Variables
 * @envi: Array to store Enviroment Variables
 */

void create_env(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_env - Function that frees the memory of the created env vars array
 * @env:  Array of env vars
 */

void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		free(env[i]);
}
