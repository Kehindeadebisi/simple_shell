#include "shell.h"
/**
 * get_cmd - gets a command from user
 *
 * Return: string
 */

char* get_cmd()
{
char *string;
size_t size = 0;
char **string_pointer = &string;
/*write(1,"#cisfun$ ", 10);*/
string = (char*) malloc (size);
getline(string_pointer,&size,stdin);
if ((strlen(string) > 0) && (string[strlen (string) - 1] == '\n'))
string[strlen (string) - 1] = '\0';
return (string);
}
