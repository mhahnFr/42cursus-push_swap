#include <unistd.h>
#include <limits.h>

#include "stack/stack.h"
#include "sort/sort.h"

#include "sort_hard.h"

void	hard_sort(struct s_stack_heads *heads)
{
	_set_indices(heads->a);
	if (heads->a->index == heads->a->next->index + 1
		|| heads->a->index + 2 == heads->a->next->index)
	{
		stack_swap(&heads->a);
		write(1, "sa\n", 3);
	}
	else if (heads->a->previous->index == 2)
	{
		stack_rotate(&heads->a, false);
		write(1, "ra\n", 3);
	}
	else if (heads->a->previous->index == 1)
	{
		stack_rotate(&heads->a, true);
		write(1, "rra\n", 4);
	}
	if (!_is_sorted(heads->a))
		hard_sort(heads);
}

/*
 * Performs either the appopriate operation, based on the state of the stacks.
 */
static void	_rotate_or_push(struct s_stack_heads *heads)
{
	if (heads->a->index < 3)
	{
		stack_push(&heads->a, &heads->b);
		write(1, "pb\n", 3);
	}
	else
	{
		stack_rotate(&heads->a, false);
		write(1, "ra\n", 3);
	}
}

void	hard_sort_big(struct s_stack_heads *heads)
{
	unsigned short	i;
	size_t			size;

	size = stack_size(heads->a);
	_set_indices(heads->a);
	i = 0;
	while (i < size)
	{
		_rotate_or_push(heads);
		i++;
	}
	hard_sort(heads);
	if (_is_sorted(heads->b))
	{
		stack_rotate(&heads->b, false);
		write(1, "rb\n", 3);
	}
	while (heads->b != NULL)
	{
		stack_push(&heads->b, &heads->a);
		write(1, "pa\n", 3);
	}
}
