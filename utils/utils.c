#include <stdlib.h>

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
