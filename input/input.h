#ifndef INPUT_H
# define INPUT_H

# include <stdbool.h>

# include "push_swap.h"

/*
 * Parses the given input. Returns false if the input is invalid.
 */
bool	input_parse(int argc, char **input, struct s_stack_heads *heads);

/*
 * Returns wether all numbers are in the range of an integer value. Returns
 * false if no stacks are given.
 */
bool	input_check(struct s_stack_heads *heads);

#endif
