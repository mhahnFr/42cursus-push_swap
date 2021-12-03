#include "input.h"

bool	input_parse(int argc, char **input, struct s_stack_heads *heads)
{
	if (argc == 1)
		return (false);
	input = (char **) heads;
	heads = (struct s_stack_heads *) input;
	return (true);
}
