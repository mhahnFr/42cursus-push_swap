#include <unistd.h>

#include "push_swap.h"
#include "input/input.h"
#include "sort/sort.h"

int	main(int argc, char **argv)
{
	struct s_stack_heads	heads;

	if (!input_parse(argc, argv, &heads))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (!is_sorted(&heads))
		sort(&heads);
	return (0);
}
