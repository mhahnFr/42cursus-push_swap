#include <stddef.h>

#include "stack.h"

bool	stack_contains(struct s_stack *this, long content)
{
	if (this == NULL)
		return (false);
	while (this != NULL)
	{
		if (this->content == content)
			return (true);
		this = this->next;
	}
	return (false);
}
