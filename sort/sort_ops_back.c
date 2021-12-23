#include "stack/stack.h"
#include "push_swap.h"
#include "sort.h"
#include "arraylist/arraylist.h"
#include "operation.h"

#include <stdio.h>
t_arraylist	*rotate_back(struct s_stack_heads *heads, t_arraylist *past)
{
	struct s_stack		*a;
	struct s_stack		*b;
	enum e_operation	op;
	t_arraylist			*tmp;
	size_t				count;

	a = heads->a;
	b = heads->b;
	tmp = past;
	count = 0;
	while (tmp != NULL)
	{
		op = (enum e_operation) tmp->content;
		if (op == RA)
			count++;
		apply_operations(&a, &b, op);
		tmp = tmp->next;
	}
/*	if (count > stack_size(a) / 2)
		while (count < stack_size(a) - 1)
		{
			arraylist_append_unsafe(&past, arraylist_new((void *) RA));
			count++;
		}
	else*/
		while (count > 0)
		{
			arraylist_append_unsafe(&past, arraylist_new((void *) RRA));
			count--;
		}
	return (past);
}
