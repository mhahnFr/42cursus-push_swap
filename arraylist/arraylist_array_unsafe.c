/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_array_unsafe.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:49:46 by mhahn             #+#    #+#             */
/*   Updated: 2021/11/25 20:49:47 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "arraylist.h"

void	**arraylist_to_array_unsafe(t_arraylist *this, t_arraylist_dup dup)
{
	void	**array;

	if (dup == NULL)
		return (NULL);
	array = malloc(arraylist_size_unsafe(this) * sizeof(void *));
	if (array == NULL)
		return (NULL);
	while (this != NULL)
	{
		array[this->index] = dup(this->content);
		this = this->next;
	}
	return (array);
}

void	**arraylist_to_array_transfer_unsafe(t_arraylist **this)
{
	void	**array;

	array = arraylist_to_array_transfer_core_unsafe(*this);
	if (array != NULL)
		arraylist_clear(this, NULL);
	return (array);
}

void	**arraylist_to_array_transfer_core_unsafe(t_arraylist *this)
{
	void	**array;

	if (this == NULL)
		return (NULL);
	array = malloc(arraylist_size_unsafe(this) * sizeof(void *));
	if (array == NULL)
		return (NULL);
	while (this != NULL)
	{
		array[this->index] = this->content;
		this = this->next;
	}
	return (array);
}
