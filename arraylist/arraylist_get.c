/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:49:50 by mhahn             #+#    #+#             */
/*   Updated: 2021/11/25 20:49:51 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

void	*arraylist_get(t_arraylist *this, size_t index)
{
	return (arraylist_get_element(this, index)->content);
}

void	*arraylist_get_unsafe(t_arraylist *this, size_t index)
{
	return (arraylist_get_element_unsafe(this, index)->content);
}

t_arraylist	*arraylist_get_element(t_arraylist *this, size_t index)
{
	size_t		counter;

	counter = 0;
	while (this != NULL)
	{
		if (counter == index)
			return (this);
		counter++;
		this = this->next;
	}
	return (NULL);
}

t_arraylist	*arraylist_get_element_unsafe(t_arraylist *this, size_t index)
{
	while (this != NULL)
	{
		if (this->index == index)
			return (this);
		this = this->next;
	}
	return (NULL);
}
