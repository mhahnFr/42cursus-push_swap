#ifndef SORT_H
# define SORT_H

# include <stddef.h>
# include <stdbool.h>

# include "push_swap.h"

/*
 * Returns wether the stacks are correctly sorted.
 */
bool	is_sorted(struct s_stack_heads *heads);

/*
 * Sorts the given stacks.
 */
void	sort(struct s_stack_heads *heads);

/*
 * Sets the indices to represent the order of the stack.
 */
void	set_indices(struct s_stack *stack);

#endif
