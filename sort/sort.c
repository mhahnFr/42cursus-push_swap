#include <stddef.h>
#include <limits.h>

#include "stack/stack.h"
#include "sort.h"

void	sort(struct s_stack_heads *heads)
{
	/*
	 * for each element
	 * 	if first
	 * 		pb
	 * 	else
	 * 		for each element in b
	 * 			if element < topB
	 * 				pb
	 * 				break
	 * 			rb
	 * 		if not pushed
	 * 			pb
	 * 	remember last element
	 */
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
	}
	return (true);
}
