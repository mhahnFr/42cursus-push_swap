/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_reset_indices.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:49:57 by mhahn             #+#    #+#             */
/*   Updated: 2021/11/25 20:49:58 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

void	arraylist_reset_indices(t_arraylist *this)
{
	arraylist_reset_indices_start(this, 0);
}

void	arraylist_reset_indices_start(t_arraylist *this, size_t start)
{
	while (this != NULL)
	{
		this->index = start++;
		this = this->next;
	}
}
