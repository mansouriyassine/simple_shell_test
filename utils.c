#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the new duplicated string,
 * or NULL if str is NULL or if memory allocation fails.
 */
char *_strdup(char *str)
{
char *dup;
int len, i;

if (!str)
return (NULL);

len = _strlen(str);

dup = malloc(sizeof(char) * (len + 1));
if (!dup)
return (NULL);

for (i = 0; i <= len; i++)
dup[i] = str[i];

return (dup);
}

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
int len = 0;

while (str[len])
len++;

return (len);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, a value less than 0
 * if s1 is less than s2, and a value greater than 0
 * if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] && s2[i] && s1[i] == s2[i])
i++;

return (s1[i] - s2[i]);
}
