#include <stddef.h>

#include "stack.h"

inline size_t	stack_size(struct s_stack *this)
{
	size_t								i;
	struct s_stack						*tmp;

	tmp = this;
	i = 0;
	while (this != NULL)
	{
		i++;
		this = this->next;
		if (this == tmp)
			break ;
	}
	return (i);
}
