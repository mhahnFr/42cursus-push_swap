#include "stack.h"

static void	stack_push_core(
				struct s_stack **this,
				struct s_stack **to)
{
	struct s_stack	*tmp;

	if (this == NULL || to == NULL || *this == NULL)
		return ;
	(*this)->previous->next = (*this)->next;
	(*this)->next->previous = (*this)->previous;
	tmp = *this;
	*this = (*this)->next;
	if (*this == tmp)
		*this = NULL;
	if (*to != NULL)
	{
		(*to)->previous->next = tmp;
		tmp->previous = (*to)->previous;
		tmp->next = *to;
		(*to)->previous = tmp;
	}
	else
	{
		tmp->previous = tmp;
		tmp->next = tmp;
	}
	*to = tmp;
}

void	stack_push_adjust(
			struct s_stack **this,
			struct s_stack **to,
			bool adjust)
{
	stack_push_core(this, to);
	if (adjust)
	{
		stack_repair_indices(*this);
		stack_repair_indices(*to);
	}
}

void	stack_push(struct s_stack **this, struct s_stack **to)
{
	stack_push_adjust(this, to, false);
}

void	stack_repair_indices(struct s_stack *this)
{
	struct s_stack	*tmp;
	size_t			ctr;

	ctr = 0;
	tmp = this;
	while (this != NULL)
	{
		this->index = ctr++;
		this = this->next;
		if (this == tmp)
			break ;
	}
}
