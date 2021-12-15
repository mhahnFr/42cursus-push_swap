#ifndef SORT_H
# define SORT_H

# include <stddef.h>
# include <stdbool.h>

# include "push_swap.h"

typedef enum e_operation	t_blub;

typedef struct s_arraylist	t_arraylist;

/*
 * Returns wether the stacks are correctly sorted.
 */
bool						is_sorted(struct s_stack_heads *heads);

/*
 * Sorts the given stacks.
 */
void						sort(struct s_stack_heads *heads);

/*
 * Returns the count of operations that would be done by the default algorithm.
 * Returns zero if no heads are given.
 */
size_t						get_ops_def(struct s_stack_heads *heads);

/*
 * Returns the count of operations that would need to be done if the topmost
 * element of stack B would be skipped.
 */
size_t						get_ops_def_next(struct s_stack_heads *heads);

t_arraylist					*get_next_operation(t_arraylist *past, struct s_stack_heads *heads);

enum e_operation			get_default_operation(
								t_arraylist *past,
								struct s_stack_heads *heads);

enum e_operation			simulate_next_operation(
								t_arraylist *past,
								struct s_stack_heads *heads);

#endif
