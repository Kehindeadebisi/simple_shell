#include "main.h"
/**
 * *read_line - read command
 * Return: the buf or null if fails
 */
 char *read_cmd(void)
 {
	 char *buf = NULL;
	 size_t bufsize = 0;

	 fflush(stdin);
	 if (getline(&buf, &bufsize, stdin) == -1)
	 {
		 free(buf);
		 return (NULL);
	 }
	 return (buf);
 }
