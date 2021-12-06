#include <stddef.h>

#include "libft.h"

#include "input.h"
#include "stack/stack.h"
#include "utils/utils.h"

bool	input_parse(int argc, char **input, struct s_stack_heads *heads)
{
	if (input == NULL || *input == NULL || heads == NULL)
		return (false);
	for (int i = 1; i < argc; i++) {
		char **s = ft_split(input[i], ' ');
		if (s == NULL || *s == NULL)
			return (false);
		for (size_t j = 0; s[j] != NULL; j++) {
			for (size_t k = 0; s[j][k] != '\0'; k++)
				if (!ft_isdigit(s[j][k]))
					return (false);
			struct s_stack *tmp = stack_new(ft_atoi(s[j]));
			if (tmp == NULL)
				return (false);
			stack_append(&heads->a, tmp);
		}
		ft_delete_split_array(s);
	}
	return (true);
}
