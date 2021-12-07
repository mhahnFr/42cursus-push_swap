#include <stddef.h>

#include "libft.h"

#include "input.h"
#include "stack/stack.h"
#include "utils/utils.h"

bool	input_append(char **array, struct s_stack **head)
{
	size_t	i;
	long	number;

	if (*array == NULL || head == NULL)
		return (false);
	i = 0;
	while (array[i] != NULL)
	{
		if (!ft_is_digits(array[i]))
			return (false);
		number = ft_atol(array[i]);
		if (stack_contains(*head, number))
			return (false);
		if (!stack_append_new(head, number))
			return (false);
		i++;
	}
	return (true);
}

bool	input_parse(int argc, char **input, struct s_stack_heads *heads)
{
	int		i;
	char	**s;
	bool	test;

	if (input == NULL || *input == NULL || heads == NULL)
		return (false);
	i = 1;
	while (i < argc)
	{
		s = ft_split(input[i], ' ');
		if (s == NULL)
			return (false);
		test = input_append(s, &heads->a);
		ft_delete_split_array(s);
		if (!test)
			return (false);
		i++;
	}
	return (true);
}
