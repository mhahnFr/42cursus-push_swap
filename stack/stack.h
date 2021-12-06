#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

/*
 * Represents a stack element. Consists of the index of the element, the value
 * and a next and previous pointer.
 */
struct s_stack {
	int				content;
	size_t			index;
	struct s_stack *next;
	struct s_stack *previous;
};

/*
 * Allocates a new element. Returns either the newly allocated element or null
 * if the allocation failed.
 */
struct s_stack	*stack_new(int content);

/*
 * Appends the given element to the given stack list. Does nothing if no
 * element to add is given.
 */
void			stack_append(struct s_stack **this, struct s_stack *appendix);

/*
 * Deletes the given stack. Does nothing if no stack is given.
 */
void			stack_delete(struct s_stack *this);

/*
 * Deletes the given list. Does nothing if no list is given.
 */
void			stack_clear(struct s_stack *this);

/*
 * Swaps the first two elements of the given stack. Does nothing if no stack is
 * given or the stack does not contain enough elements.
 */
void			swap(struct s_stack **this);

/*
 * Pushes the first element of the given stack to the other one. Does nothing
 * if at least one stack is missing or no elements are left in the given stack.
 */
void			push(struct s_stack **this, struct s_stack **to);

/*
 * Rotates the elements in the given stack. If reverse is false, the first
 * element will become the last one. Otherwise, the last elements will become
 * the first one.
 */
void			rotate(struct s_stack **this, bool reverse);

#endif
