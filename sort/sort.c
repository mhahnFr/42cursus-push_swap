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
//		size_t c = get_ops_def(heads);
//		size_t o = get_ops_def_next(heads);
//		if (c -5 > o) {
//			stack_rotate(&heads->b, false);
//			printf("rb\n");
//		}
//		printf("Default: %zuNext: %zu\n", c, o);
		bool inserted = false;
		size_t b_size = stack_size(heads->a);
		for (size_t j = 0; j < b_size && !inserted; j++) {
			if (heads->b->content < heads->a->content) {
				stack_push(&heads->b, &heads->a);
				printf("pa\n");
				inserted = true;
				size_t sta = stack_size(heads->a);
				if (j <= sta / 2) {
					for (size_t ctr = 0; ctr <= j; ctr++) {
						stack_rotate(&heads->a, true);
						printf("rra\n");
					}
				} else {
					for (size_t ctr = 0; ctr < sta - j - 1; ctr++) {
						stack_rotate(&heads->a, false);
						printf("ra\n");
					}
				}
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
