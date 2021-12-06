#include <stddef.h>

#include "libft.h"

#include "input.h"
#include "stack/stack.h"
#include "utils/utils.h"

bool	input_parse(int argc, char **input, struct s_stack_heads *heads)
{
	int				i;
	size_t			j;
	char			**s;
	struct s_stack	*tmp;

	if (input == NULL || *input == NULL || heads == NULL)
		return (false);
	i = 1;
	while (i < argc)
	{
		s = ft_split(input[i], ' ');
		if (s == NULL || *s == NULL)
			return (false);
		j = 0;
		while (s[j] != NULL)
		{
			if (!ft_is_digits(s[j]))
				return (false);
			tmp = stack_new(ft_atoi(s[j]));
			if (tmp == NULL)
				return (false);
			stack_append(&heads->a, tmp);
			j++;
		}
		ft_delete_split_array(s);
		i++;
	}
	return (true);
}
