#include <unistd.h>

#include "push_swap.h"
#include "input/input.h"
#include "sort/sort.h"
#include "stack/stack.h"
#include "sort/hard/sort_hard.h"

/*
 * Delegates the given stack to the appopriate sorting algorithm.
 */
static void	delegate_sort(struct s_stack_heads *heads)
{
	size_t	s_size;

	s_size = stack_size(heads->a);
	if (s_size <= 3)
		hard_sort(heads);
	else if (s_size <= 5)
		hard_sort_big(heads);
	else
		sort(heads);
}

/*
 * Handles the input and invokes the sorting algorithm.
 */
static void	delegate(int argc, char **argv, struct s_stack_heads *heads)
{
	heads->a = NULL;
	heads->b = NULL;
	if (!input_parse(argc, argv, heads) || !input_check(heads))
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (!is_sorted(heads))
		delegate_sort(heads);
}

int	main(int argc, char **argv)
{
	struct s_stack_heads	heads;

	delegate(argc, argv, &heads);
	stack_clear(heads.a);
	stack_clear(heads.b);
}
