#include <limits.h>
#include <stddef.h>

#include "input.h"
#include "stack/stack.h"

bool	input_check(struct s_stack_heads *heads)
{
	struct s_stack	*tmp;

	if (heads == NULL)
		return (false);
	tmp = heads->a;
	while (tmp != NULL)
	{
		if (tmp->content < INT_MIN || tmp->content > INT_MAX)
			return (false);
		tmp = tmp->next;
		if (tmp == heads->a)
			break ;
	}
	return (true);
}
