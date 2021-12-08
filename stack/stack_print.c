#include <stdio.h>

#include "stack.h"

void	stack_print(struct s_stack *this)
{
	if (this == NULL) {
		printf("(null)\n");
		return;
	}
	printf("\n---\n");
	while (this != NULL) {
		printf("Index: %zu: %ld\n", this->index, this->content);
		this = this->next;
	}
}
