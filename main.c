#include "main.h"
int main(void)
{
	char *cmd;
	struct source_s src;
do
{
	print_prompt();

	cmd = read_cmd();

	if(!cmd)
	{
		exit(EXIT_SUCCESS);
	}

	if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
	{
		free(cmd);
		continue;
	}

	if(strcmp(cmd, "exit\n") == 0)
	{
		free(cmd);
		break;
	}

	src.buffer   = cmd;
	src.bufsize  = strlen(cmd);
	src.curpos   = INIT_SRC_POS;
	parse_and_execute(&src);

	free(cmd);

} while(1);

exit(EXIT_SUCCESS);
}
