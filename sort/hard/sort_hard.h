#ifndef SORT_HARD_H
# define SORT_HARD_H

# include "push_swap.h"

/*
 * Sorts the given stacks with at most three elements using a hardcoded
 * pattern.
 */
void	hard_sort(struct s_stack_heads *heads);

/*
 * Sorts the given stacks with at most five elements using a hardcoded pattern.
 */
void	hard_sort_big(struct s_stack_heads *heads);

/*
 * Sets the indices to represent the order of the stack.
 */
void	_set_indices(struct s_stack *stack);

/*
 * Returns wether the stacks are correctly sorted.
 */
bool	_is_sorted(struct s_stack *stack);

#endif
