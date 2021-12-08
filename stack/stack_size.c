#include <stddef.h>

#include "stack.h"

inline size_t	stack_size(struct s_stack *this)
{
	if (this == NULL)
		return (0);
	return (this->previous->index + 1);
}
