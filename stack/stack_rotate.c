#include "stack.h"

void	stack_rotate(struct s_stack **this, bool reverse)
{
	stack_rotate_adjust(this, reverse, false);
}

void	stack_rotate_adjust(
			struct s_stack **this,
			bool reverse,
			bool adjustIndices)
{
	if (this == NULL || stack_size(*this) <= 1)
		return ;
	if (reverse)
		*this = (*this)->previous;
	else
		*this = (*this)->next;
	if (adjustIndices)
		stack_repair_indices(*this);
}
