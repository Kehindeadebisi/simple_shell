#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *main - getsline
 *Return: 0
 */


int main(void)
{
	char *buffer;
	size_t buff_size = 1024;

	buffer = malloc(buff_size * sizeof(char));
	if (buffer == NULL)
	{
		perror("Cannot allocate memory");
	}
	printf("$ ");

	while (buffer)
	{
		if (feof(stdin))
		{
			break;
		}
		getline(&buffer, &buff_size, stdin);
		printf("%s", buffer);
	}
	return (0);
}
