#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

char *string;
size_t size = 0;
char *argv[16];
pid_t pid;
char i;

void get_cmd();
void convert_cmd();
void c_shell();

int main(){
c_shell();

return 0;
}

void c_shell(){
while(1){
get_cmd();
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
convert_cmd();
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
if(NULL == argv[i]) waitpid(pid, NULL, 0);
}
}
}

void get_cmd(){
char **string_pointer = &string;
write(1,"#cisfun$ ", 10);
string = (char*) malloc (size);
getline(string_pointer,&size,stdin);
if ((strlen(string) > 0) && (string[strlen (string) - 1] == '\n'))
string[strlen (string) - 1] = '\0';
}

void convert_cmd(){
char *ptr;
i = 0;
ptr = strtok(string, " ");
while(ptr != NULL){
argv[i] = ptr;
i++;
ptr = strtok(NULL, " ");
}
}
