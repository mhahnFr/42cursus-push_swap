#include <limits.h>

#include "stack/stack.h"
#include "sort_hard.h"

/*
 * Searches for the smallest number in the given stack that is bigger than the
 * given number. The element of the stack containing that number will get the
 * indicated index. Returns the smallest appopriate number found.
 */
static size_t	_find_smallest(
					struct s_stack *stack,
					long minimum,
					size_t stack_size,
					size_t new_index)
{
	long	min;
	size_t	i;

	i = 0;
	min = (long) INT_MAX + 1;
	while (i < stack_size)
	{
		if (stack->content < min && stack->content > minimum)
		{
			stack->index = new_index;
			min = stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (min);
}

void	_set_indices(struct s_stack *stack)
{
	size_t	i;
	size_t	size;
	long	stop;

	stop = (long) INT_MIN - 1;
	i = 1;
	size = stack_size(stack);
	while (i <= size)
	{
		stop = _find_smallest(stack, stop, size, i);
		i++;
	}
}

bool	_is_sorted(struct s_stack *stack)
{
	struct s_stack	*tmp;
	long			i_tmp;

	i_tmp = (long) INT_MIN - 1;
	tmp = stack;
	while (tmp != NULL)
	{
		if (i_tmp < tmp->content)
			i_tmp = tmp->content;
		else
			return (false);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (true);
}
