#include <stdlib.h>

#include "stack.h"

struct s_stack	*stack_new(long content)
{
	struct s_stack	*ret;

	ret = malloc(sizeof(struct s_stack));
	if (ret == NULL)
		return (NULL);
	ret->content = content;
	ret->previous = NULL;
	ret->next = NULL;
	ret->index = 0;
	return (ret);
}

bool	stack_append_new(struct s_stack **this, long content)
{
	struct s_stack	*tmp;

	if (this == NULL)
		return (false);
	tmp = stack_new(content);
	if (tmp == NULL)
		return (false);
	stack_append(this, tmp);
	return (true);
}

void	stack_append(struct s_stack **this, struct s_stack *appendix)
{
	if (this == NULL)
		return ;
	else if (*this == NULL)
	{
		*this = appendix;
		(*this)->index = 0;
		(*this)->previous = *this;
		(*this)->next = *this;
		return ;
	}
	(*this)->previous->next = appendix;
	appendix->previous = (*this)->previous;
	(*this)->previous = appendix;
	appendix->next = *this;
	appendix->index = appendix->previous->index + 1;
}

void	stack_delete(struct s_stack *this)
{
	if (this == NULL)
		return ;
	free(this);
}

void	stack_clear(struct s_stack *this)
{
	struct s_stack	*n;
	struct s_stack	*tmp;

	tmp = this;
	while (this != NULL)
	{
		n = this->next;
		stack_delete(this);
		this = n;
		if (this == tmp)
			break ;
	}
}
