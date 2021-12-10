#include <stddef.h>
#include <limits.h>
#include <unistd.h>

#include "stack/stack.h"
#include "sort.h"

#include <stdio.h>
void	sort(struct s_stack_heads *heads)
{
	size_t a_size = stack_size(heads->a);
	for (size_t i = 0; i < a_size; i++) {
		stack_push(&heads->a, &heads->b);
		printf("pb\n");
	}
	bool first = true;
	while (heads->b != NULL) {
//		stack_heads_print(heads);
		if (first) {
			stack_push(&heads->b, &heads->a);
			printf("pa\n");
			first = false;
		} else {
			size_t b_size = stack_size(heads->a);
			bool inserted = false;
			for (size_t j = 0; j < b_size; j++) {
				if (heads->b->content < heads->a->content) {
					stack_push(&heads->b, &heads->a);
					printf("pa\n");
					stack_rotate(&heads->a, false);
					printf("ra\n");
					inserted = true;
					for (size_t ctr = 0; ctr <= j; ctr++) {
						stack_rotate(&heads->a, true);
						printf("rra\n");
					}
					break;
				}
				stack_rotate(&heads->a, false);
				printf("ra\n");
			}
			if (!inserted) {
				stack_push(&heads->b, &heads->a);
				printf("pa\n");
				stack_rotate(&heads->a, false);
				printf("ra\n");
			}
		}
	}
//	stack_heads_print(heads);
//	a_size = stack_size(heads->b);
//	for (size_t i = 0; i < a_size; i++) {
//		stack_push(&heads->b, &heads->a);
//		printf("pa\n");
//	}
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
