#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
/*char i;*/
char* get_cmd();
char** tokenize_cmd(char *str);
void c_shell();

#endif
