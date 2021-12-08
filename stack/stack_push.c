#include "stack.h"

void	stack_push(struct s_stack **this, struct s_stack **to)
{
	struct s_stack	*tmp;

	if (this == NULL || to == NULL || (*this == NULL && *to == NULL))
		return ;
	tmp = (*this)->next;
	if (*to != NULL)
		stack_append(this, *to);
	*to = *this;
	*this = tmp;
	stack_repair_indices(*this);
	stack_repair_indices(*to);
}

void	stack_repair_indices(struct s_stack *this)
{
	size_t	ctr;

	ctr = 0;
	while (this != NULL)
	{
		this->index = ctr++;
		this = this->next;
	}
}
