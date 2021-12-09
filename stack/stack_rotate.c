#include "stack.h"

void	stack_rotate(struct s_stack **this, bool reverse)
{
	if (this == NULL || stack_size(*this) <= 1)
		return ;
	if (reverse)
		*this = (*this)->previous;
	else
		*this = (*this)->next;
	stack_repair_indices(*this);
}
