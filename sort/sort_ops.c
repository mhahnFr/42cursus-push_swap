#include <stddef.h>

#include "sort.h"
#include "stack/stack.h"
#include "push_swap.h"

size_t	get_ops_def(struct s_stack_heads *heads)
{
	struct s_stack *tmp;
	size_t			count;

	count = 0;
	tmp = heads->a;
	while (tmp != NULL)
	{
		if (heads->b->content < tmp->content)
			break ;
		tmp = tmp->next;
		count++;
		if (tmp == heads->a)
			break ;
	}
	return (count);
}

size_t	get_ops_def_next(struct s_stack_heads *heads)
{
	struct s_stack *tmp;
	size_t			count;

	count = 0;
	tmp = heads->a;
	while (tmp != NULL)
	{
		if (heads->b->next->content < tmp->content)
			break ;
		tmp = tmp->next;
		count++;
		if (tmp == heads->a)
			break ;
	}
	return (count);
}
