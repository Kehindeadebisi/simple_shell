#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>
void print_prompt(void);

char *read_cmd(void);
/*source*/

#define EOF             (-1)
#define ERRCHAR         ( 0)

#define INIT_SRC_POS    (-2)

struct source_s
{
	char *buffer;
	long bufsize;
	long  curpos;
};

char next_char(struct source_s *src);
void unget_char(struct source_s *src);
char peek_char(struct source_s *src);
void skip_white_spaces(struct source_s *src);
int  parse_and_execute(struct source_s *src);
/*tokenize*/

struct token_s
{
	struct source_s *src;
	int    text_len;
	char   *text;
};
extern struct token_s eof_token;

struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);

/*parse*/
struct node_s *parse(struct token_s *tok);

/*node*/

enum node_type_e
{
NODE_COMMAND,
NODE_VAR
};

enum val_type_e
{
VAL_SINT = 1,
VAL_UINT,
VAL_SLLONG,
VAL_ULLONG,
VAL_FLOAT,
VAL_LDOUBLE,
VAL_CHR,
VAL_STR
};

union symval_u
{
long               sint;
unsigned long      uint;
long               sllong;
unsigned long      ullong;
double             sfloat;
long double        ldouble;
char               chr;
char              *str;
};

struct node_s
{
enum   node_type_e type;
enum   val_type_e val_type;
union  symval_u val;
int    children;
struct node_s *first_child;
struct node_s *next_sibling, *prev_sibling;
};

struct  node_s *new_node(enum node_type_e type);
void    add_child_node(struct node_s *parent, struct node_s *child);
void    free_node_tree(struct node_s *node);
void    set_node_val_str(struct node_s *node, char *val);

/*executer*/
char *search_path(char *file);
int do_exec_cmd(int argc, char **argv);
int do_simple_command(struct node_s *node);

#endif
