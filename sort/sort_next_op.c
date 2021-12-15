#include "operation.h"
#include "sort.h"
#include "stack/stack.h"

#include "arraylist.h"

#include <stdio.h>
t_arraylist	*get_next_operation(t_arraylist *past, struct s_stack_heads *heads)
{
	enum e_operation	next;

	if (past != NULL && (enum e_operation) past->previous->content == PA)
		return (past);
	next = NONE;
	if (arraylist_size_unsafe(past) == 0)
		next = get_default_operation(past, heads);
	if (next == NONE)
		next = get_default_operation(past, heads);
	//	next = simulate_next_operation(past, heads);
	arraylist_append_unsafe(&past, arraylist_new((void *) next));
	printf("%p\n", past->previous->content);
	return (get_next_operation(past, heads));
}

void	apply_operations(
			struct s_stack **a,
			struct s_stack **b,
			enum e_operation operation)
{
	if (operation == RA || operation == RR)
		*a = (*a)->next;
	if (operation == RB || operation == RR)
		*b = (*b)->next;
	if (operation == RRA || operation == RRR)
		*a = (*a)->previous;
	if (operation == RRB || operation == RRR)
		*b = (*b)->previous;
	// TODO apply more possibilities
}

enum e_operation	get_default_operation(t_arraylist *past, struct s_stack_heads *heads)
{
	struct s_stack	*a;
	struct s_stack	*b;

	a = heads->a;
	b = heads->b;
	while (past != NULL)
	{
		apply_operations(&a, &b, (enum e_operation) past->content);
		past = past->next;
	}
	if (b->content < a->content)
		return (PA);
	return (RA);
}

/*enum e_operation	simulate_next_operation(t_arraylist *past, struct s_stack_heads *heads)
{
	size_t			no;
	struct s_stack	*a;
	struct s_stack	*b;

	no = arraylist_size_unsafe(past);
	if (no == 0)
		return (NONE);
	while (past != NULL)
	{
		// Simulate it
	}
	// return next operation
}*/
