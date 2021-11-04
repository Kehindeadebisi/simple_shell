#include "shell.h"
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
