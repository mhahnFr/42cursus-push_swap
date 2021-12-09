#include <stdio.h>

#include "stack.h"

void	stack_print(struct s_stack *this)
{
	struct s_stack	*tmp;

	if (this == NULL) {
		printf("(null)\n");
		return;
	}
	printf("\n---\n");
	tmp = this;
	do {
		printf("Index: %zu: %ld\n", this->index, this->content);
		this = this->next;
	} while (this != tmp);
}
