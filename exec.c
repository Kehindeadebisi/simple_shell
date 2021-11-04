#include "main.h"
int parse_and_execute(struct source_s *src)
{
	struct token_s *tok;
	struct node_s *cmd;
	skip_white_spaces(src);

	tok = tokenize(src);

	if(tok == &eof_token)
	{
		return 0;
	}

	while(tok && tok != &eof_token)
	{
		cmd = parse(tok);

		if(!cmd)
		{
			break;
		}

		do_simple_command(cmd);
		free_node_tree(cmd);
		tok = tokenize(src);
	}

	return 1;
}
