#include <stdlib.h>

#include "libft.h"

#include "utils.h"

void	ft_delete_split_array(char **array)
{
	size_t	i;

	if (array == NULL)
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

	if (string == NULL || *string == '\0')
		return (false);
	i = 0;
	if (string[i] == '-' || string[i] == '+')
		i++;
	if (string[i] == '\0')
		return (false);
	while (string[i] != '\0')
	{
		if (!ft_isdigit(string[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_isspace(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

long	ft_atol(char *string)
{
	size_t	counter;
	char	sign;
	long	ret;

	counter = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(string[counter]))
		counter++;
	if (string[counter] == '+')
		counter++;
	else if (string[counter] == '-')
	{
		sign = -1;
		counter++;
	}
	while (ft_isdigit(string[counter]))
	{
		ret = (ret * 10) + (string[counter] - '0');
		counter++;
	}
	return (ret * sign);
}
