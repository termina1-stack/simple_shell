#include "simple_shell.h"

/**
 * _strcmp - Function that compares two string
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if identical
 */
int _strcmp(char *str1, char *str2)
{
	int cmp = 0, i, len1, len2;

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			cmp = str1[i] - str2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - Function that checks for alphabet
 * @c: character
 * Return: 1 if true, else 0
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);
	else
		return (0);
}

/**
 * _itoa - Funciton that converts an integer to a character
 * @n: integer value
 * Return: A character pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = int_len(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';

	return (s);
}

/**
 * array_rev - Function that reverse an array of strings
 * @arr: array to reverse
 * @len: length of our array
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * int_len - Function that finds length of an integer
 * @num: given integer
 * Return: length of integer
 */
int int_len(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
