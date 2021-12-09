#include <stdio.h>

#include "stack.h"
#include "push_swap.h"

void	stack_print(struct s_stack *this)
{
	struct s_stack	*tmp;

	if (this == NULL) {
		printf("(null)\n");
		return;
	}
	tmp = this;
	do {
		printf("Index: %zu: %ld\n", this->index, this->content);
		this = this->next;
	} while (this != tmp);
}

void	stack_heads_print(struct s_stack_heads *this) {
	printf("\n---");
	printf("\nA:\n");
	stack_print(this->a);
	printf("\nB:\n");
	stack_print(this->b);
	printf("---\n");
}
