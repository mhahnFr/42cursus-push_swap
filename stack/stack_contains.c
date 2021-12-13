#include <stddef.h>

#include "stack.h"

bool	stack_contains(struct s_stack *this, long content)
{
	struct s_stack	*tmp;

	if (this == NULL)
		return (false);
	tmp = this;
	while (this != NULL)
	{
		if (this->content == content)
			return (true);
		this = this->next;
		if (this == tmp)
			break ;
	}
	return (false);
}

bool	stack_is_in_range(struct s_stack *this, long content)
{
	if (this == NULL || stack_size(this) <= 1)
		return (false);
	return (/*this->content < content && */this->previous->content > content);
}
