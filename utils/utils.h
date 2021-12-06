#ifndef UTILS_H
# define UTILS_H

/*
 * Deletes an array that has been produced by the libft function "ft_split()".
 * The array has to contain allocated strings, the last element of the array
 * has to be a null pointer.
 */
void	ft_delete_split_array(char **array);

#endif
