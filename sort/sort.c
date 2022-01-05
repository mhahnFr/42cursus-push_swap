#include <stddef.h>
#include <limits.h>
#include <unistd.h>

#include "stack/stack.h"
#include "sort.h"

/*
 * Searches for the smallest number in the given stack that is bigger than the
 * given number. The element of the stack containing that number will get the
 * indicated index. Returns the smallest appopriate number found.
 */
static size_t	find_smallest(
					struct s_stack *stack,
					long minimum,
					size_t stack_size,
					size_t new_index)
{
	long	min;
	size_t	i;

	i = 0;
	min = INT_MAX;
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

void	set_indices(struct s_stack *stack)
{
	size_t	i;
	size_t	size;
	long	stop;

	stop = (long) INT_MIN - 1;
	i = 1;
	size = stack_size(stack);
	while (i <= size)
	{
		stop = find_smallest(stack, stop, size, i);
		i++;
	}
}

static void	push_or_rotate(struct s_stack_heads *heads, size_t bit_count)
{
	if ((heads->a->index >> bit_count & 1) == 0)
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

void	sort(struct s_stack_heads *heads)
{
	size_t	i;
	size_t	si;
	size_t	init_size;

	init_size = stack_size(heads->a);
	set_indices(heads->a);
	si = 0;
	while (!is_sorted(heads) && si < 32)
	{
		i = 0;
		while (i < init_size)
		{
			push_or_rotate(heads, si);
			i++;
		}
		while (heads->b != NULL)
		{
			stack_push(&heads->b, &heads->a);
			write(1, "pa\n", 3);
		}
		si++;
	}
}

bool	is_sorted(struct s_stack_heads *heads)
{
	struct s_stack	*tmp;
	long			i_tmp;

	if (heads == NULL)
		return (true);
	if (heads->b != NULL)
		return (false);
	i_tmp = (long) INT_MIN - 1;
	tmp = heads->a;
	while (tmp != NULL)
	{
		if (i_tmp < tmp->content)
			i_tmp = tmp->content;
		else
			return (false);
		tmp = tmp->next;
		if (tmp == heads->a)
			break ;
	}
	return (true);
}
