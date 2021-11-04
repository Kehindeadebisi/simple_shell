#include "shell.h"

void c_shell()
{
char *string;
pid_t pid;
char **argv;
int i, j;
while(1)
{
write(1,"#cisfun$ ", 10);
string = get_cmd();
if(!strcmp("", string))
{
free(string);
continue;
}
if(strcmp(string, "exit") == 0)
{
free(string);
break;
}
argv = tokenize_cmd(string);
j = sizeof(argv) / sizeof(char);
pid = fork();
if(-1 == pid){
write(1,"failed to create a child", 17);
}
else if(0 == pid){
if (execve(argv[0], argv, NULL) == -1)
{
perror("./shell");
}
}
else{
for (i = 0; i < j; i++)
{
i++;
}
if(NULL == argv[i]) waitpid(pid, NULL, 0);
}
}
}
