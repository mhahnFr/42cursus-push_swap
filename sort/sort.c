#include <stddef.h>
#include <limits.h>
#include <unistd.h>

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
	 * 			rrb
	 * 		if not pushed
	 * 			pb
	 * 	remember last element
	 */
	size_t a_size = stack_size(heads->a);
	for (size_t i = 0; i < a_size; i++) {
		if (i == 0) {
			stack_push(&heads->a, &heads->b);
			write(1, "pb\n", 3);
		} else {
			size_t b_size = stack_size(heads->b);
			bool inserted = false;
			for (size_t j = 0; j < b_size; j++) {
				if (heads->a->content < heads->b->content) {
					stack_push(&heads->a, &heads->b);
					write(1, "pb\n", 3);
					inserted = true;
					break;
				}
				stack_rotate(&heads->b, false);
				write(1, "rb\n", 3);
			}
			if (!inserted) {
				stack_push(&heads->a, &heads->b);
				write(1, "pb\n", 3);
			}
		}
	}
	a_size = stack_size(heads->b);
	for (size_t i = 0; i < a_size; i++) {
		stack_push(&heads->b, &heads->a);
		write(1, "pa\n", 3);
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
