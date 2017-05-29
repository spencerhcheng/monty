#include "monty.h"

/**
 * _strlen - counts characters in string
 * @str: string to count characters from
 * Return: string's char count
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;

	return (i);
}

/**
 * _strncmp - compare 2 strings up to a desginated index
 * @str1: first string in comparison
 * @str2: second string in comparison
 * @n: index to compare up to
 * Return: 0 on match; non-zero on non-match
 */

int _strncmp(char *str1, char *str2, int n)
{
	int i;

	i = 0;
	while (*(str1 + i) != '\0' && *(str2 + i) != '\0' && i < n)
	{
		if (*(str1 + i) == *(str2 + i))
		{
			++i;
		}
		else
		{
			return (*(str1 + i) - *(str2 + i));
		}
	}
	if (i == n && (*(str1 + i) == ' ' || *(str1 + i) == '\t' ||
				   *(str1 + i) == '\0' || *(str1 + i) == '\n'))
	{
		return (0);
	}
	return (EXIT_FAILURE);
}

/**
 * _atoi - converts a string with numbers into an int
 *@s: string to convert
 * Return: int converted fro string
 */

int _atoi(char *s)
{
	int i = 0;
	int result;
	int neg_count;

	result = neg_count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			neg_count++;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			for ( ; s[i] >= '0' && s[i] <= '9'; i++)
			{
				result = result * 10 - (s[i] - '0');
			}
			break;
		}
	}
	if (neg_count % 2 == 0)
	{
		result *= -1;
	}
	else
	{
		result *= 1;
	}
	return (result);
}
/**
 * _strcmp - compares two strings for equality
 *
 * @s1: first string in comparison
 * @s2: second string in comparison
 *
 * Return: 0 if equal; 1 if not equal
 */

int _strcmp(char *s1, char *s2)
{
	for ( ; *s1 && (*s1 == *s2); s1++, s2++)
		;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
