#include <stddef.h>
#include <limits.h>
#include <unistd.h>

#include "stack/stack.h"
#include "sort.h"

// 150 elements: 1715 ops
#include <stdio.h>
void	sort(struct s_stack_heads *heads)
{
	while (stack_size(heads->a) > 1) {
		stack_push(&heads->a, &heads->b);
		printf("pb\n");
	}
	while (heads->b != NULL) {
		bool inserted = false;
//		if (stack_is_in_range(heads->a, heads->b->content)) {
			size_t b_size = stack_size(heads->a);
			for (size_t j = 0; j < b_size && !inserted; j++) {
				if (heads->b->content < heads->a->content) {
					stack_push(&heads->b, &heads->a);
					printf("pa\n");
					inserted = true;
					for (size_t ctr = 0; ctr <= j; ctr++) {
						stack_rotate(&heads->a, true);
						printf("rra\n");
					}
				}
				stack_rotate(&heads->a, false);
				printf("ra\n");
			}
//		}
		if (!inserted) {
			stack_push(&heads->b, &heads->a);
			printf("pa\n");
			stack_rotate(&heads->a, false);
			printf("ra\n");
		}
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
		if (tmp == heads->a)
			break ;
	}
	return (true);
}
