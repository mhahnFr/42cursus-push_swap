#include <unistd.h>

#include "push_swap.h"
#include "input/input.h"
#include "sort/sort.h"
#include "stack/stack.h"

void	delegate(int argc, char **argv, struct s_stack_heads *heads)
{
	heads->a = NULL;
	heads->b = NULL;
	if (!input_parse(argc, argv, heads) || !input_check(heads))
	{
		write(2, "Error\n", 6);
		return ;
	}
//	stack_heads_print(heads);
	if (!is_sorted(heads))
		sort(heads);
//	stack_heads_print(heads);
}

int	main(int argc, char **argv)
{
	struct s_stack_heads	heads;

	delegate(argc, argv, &heads);
	stack_clear(heads.a);
	stack_clear(heads.b);
}
