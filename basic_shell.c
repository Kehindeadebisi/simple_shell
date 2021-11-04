#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <strings.h>

int main()
{
	size_t buff_size = 32;
	char *buffer;
	char *argv[] = {"/bin/ls", NULL};

	buffer = (char *)malloc(buff_size * sizeof(char));
	if (buffer == NULL)
	exit(1);

	while (buffer)
	{
		printf("$ ");
		if (feof(stdin))
		{
			break;
		}
		else
		{
		getline(&buffer, &buff_size, stdin);

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error: Cannot find command");
		}
		return (0);
		}
	}
	return (0);
}
