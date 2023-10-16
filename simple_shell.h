#ifndef SIMPLE_SHELL_HEADER_H
#define SIMPLE_SHELL_HEADER_H
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFFSIZE 10240
#define DELIMITER " \t\r\n\a"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>


/**
 * struct _builtin - conatins built-in commands
 * @command: - Built-in command
 * @function: - Pointer to custom functions
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *str1, char *str2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int int_len(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
void free_env(char **env);
void *fill_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *ptr);
char *_getline(void);
char *space(char *str);
char *enter(char *str);
void hashtag_handler(char *buf);
unsigned int delim_checker(char c, const char *str);
char *_strtok(char *str, const char *delim);
int shell_history(char *input);
char **spliter(char *input);
void read_file(char *file, char **argv);
void treat_file(char *line, int count, FILE *fp, char **argv);
void exit_stat_file(char **cmd, char *line, FILE *fd);
char **command_parser(char *input);
int handle_builtin_cmd(char **cmd, int er);
int execute_cmd(char **cmd, char *input, int c, char **argv);
void signal_to_handle(int sig);
void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_msg(char **argv, int c);
extern char **environ;
void create_env(char **envi);
void free_env(char **env);
void print_number(unsigned int n);
void print_number_int(int n);
int print_echo(char **cmd);
int path_cmd(char **cmd);
char *build(char *token, char *value);
char *_getenv(char *name);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_shell(void);
int display_help(char **cmd, __attribute__((unused))int st);

/****** BUILTIN COMMAND HANDLERS AND EXECUTE ******/

int check_builtin_cmd(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_stat(char **cmd, char *input, char **argv, int c,
		int stat);
int change_dir(char **cmd, __attribute__((unused))int st);
int dis_env(__attribute__((unused)) char **cmd,
		__attribute__((unused)) int st);
int echo_bul(char **cmd, int st);
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused)) int st);


#endif
