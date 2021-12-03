#include <stdlib.h>

#include "stack.h"

struct s_stack	*stack_new(int content)
{
	struct s_stack	*ret;

	ret = malloc(sizeof(struct s_stack));
	if (ret == NULL)
		return (NULL);
	ret->content = content;
	return (ret);
}

void	stack_append(struct s_stack **this, struct s_stack *appendix)
{
}

void	stack_delete(struct s_stack *this)
{
	if (this == NULL)
		return ;
	free(this);
}
