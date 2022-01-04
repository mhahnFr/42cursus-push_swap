#include "stack.h"

void	stack_swap(struct s_stack **this)
{
	stack_swap_adjust(this, false);
}

void	stack_swap_adjust(struct s_stack **this, bool adjust)
{
	struct s_stack	*tmp;

	if (this == NULL || stack_size(*this) < 2)
		return ;
	tmp = (*this)->next;
	(*this)->previous->next = tmp;
	tmp->previous = (*this)->previous;
	(*this)->next = tmp->next;
	tmp->next->previous = *this;
	(*this)->previous = tmp;
	tmp->next = *this;
	*this = tmp;
	if (adjust)
		stack_repair_indices(*this);
}
