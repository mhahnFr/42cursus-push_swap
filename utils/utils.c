#include <stdlib.h>

#include "libft.h"

#include "utils.h"

void	ft_delete_split_array(char **array)
{
	size_t	i;

	if (array == NULL || *array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	ft_is_digits(char *string)
{
	size_t	i;

	if (string == NULL)
		return (false);
	i = 0;
	while (string[i] != '\0')
	{
		if (!ft_isdigit(string[i]))
			return (false);
		i++;
	}
	return (true);
}
