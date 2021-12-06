#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

/*
 * Deletes an array that has been produced by the libft function "ft_split()".
 * The array has to contain allocated strings, the last element of the array
 * has to be a null pointer.
 */
void	ft_delete_split_array(char **array);

/*
 * Returns wether the given string contains only digits. If no string is given,
 * false is returned.
 */
bool	ft_is_digits(char *string);

#endif
