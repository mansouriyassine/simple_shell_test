#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if allocation fails
 */
char *_strdup(const char *str)
{
if (!str)
return (NULL);

int len = strlen(str);
char *dup = malloc(len + 1);

if (!dup)
return (NULL);

strcpy(dup, str);
return (dup);
}

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: Negative value if s1 < s2, positive value if s1 > s2, 0 if equal
 */
int _strcmp(const char *s1, const char *s2)
{
while (*s1 && *s1 == *s2)
{
s1++;
s2++;
}

return (*s1 - *s2);
}

/**
 * _putchar - Write a character to stdout
 * @c: The character to write
 *
 * Return: Number of characters written
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_number - Print an integer
 * @n: The integer to print
 */
void print_number(int n)
{
if (n < 0)
{
_putchar('-');
n = -n;
}

if (n / 10)
print_number(n / 10);

_putchar(n % 10 + '0');
}
