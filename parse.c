#include "shell.h"
/**
 * tokenize_cmd - split strings and store in array
 * str: a string to be parse
 * Return: array of string
 */
char** tokenize_cmd(char *str)
{
static char *argv[16];
char *ptr;
int i = 0;
ptr = strtok(str, " ");
while(ptr != NULL)
{
argv[i] = ptr;
i++;
ptr = strtok(NULL, " ");
}
return (argv);
}
