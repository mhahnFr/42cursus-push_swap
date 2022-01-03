#include <stddef.h>
#include <limits.h>
#include <unistd.h>

#include "arraylist.h"

#include "operation.h"
#include "stack/stack.h"
#include "sort.h"

#include <stdio.h>
void	set_indices(struct s_stack *stack)
{
	size_t			i;
	size_t			a;
	size_t			size;
	long			min;
	long			stop;

	stop = INT_MIN;
	a = 0;
	size = stack_size(stack);
	while (a < size)
	{
		i = 0;
		min = INT_MAX;
		while (i < size)
		{
			if (stack->content < min && stack->content > stop)
			{
				stack->index = a;
				min = stack->content;
			}
			stack = stack->next;
			i++;
		}
		stop = min;
		a++;
	}
}

void	sort(struct s_stack_heads *heads)
{
	size_t	i;
	size_t	init_size;

	init_size = stack_size(heads->a);
	set_indices(heads->a);
	size_t si = 0;
	while (si < 32)
	{
		i = 0;
		while (i < init_size)
		{
			if ((heads->a->index >> si & 1) == 0)
			{
				stack_push(&heads->a, &heads->b);
				printf("pb\n");
			}
			else
			{
				stack_rotate(&heads->a, false);
				printf("ra\n");
			}
			i++;
		}
		while (heads->b != NULL)
		{
			stack_push(&heads->b, &heads->a);
			printf("pa\n");
		}
		si++;
	}
	// Check how many binary digits are needed.
}

bool	is_sorted(struct s_stack_heads *heads)
{
	struct s_stack	*tmp;
	long			i_tmp;

	if (heads == NULL)
		return (true);
	if (heads->b != NULL)
		return (false);
	i_tmp = INT_MIN;
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
