#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 * Stores the heads of the stacks.
 */
struct s_stack_heads {
	struct s_stack	*a;
	struct s_stack	*b;
};

/*
 * Prints the stacks.
 */
void	stack_heads_print(struct s_stack_heads *this);

/*
 * Swaps the first two elements in the stack A.
 */
void	sa(struct s_stack_heads *heads);

/*
 * Swaps the first two elements in the stack B.
 */
void	sb(struct s_stack_heads *heads);

/*
 * Swaps the first two elements in each stack, respectively.
 */
void	ss(struct s_stack_heads *heads);

/*
 * Pushes the top most element of stack B to the top of stack A.
 */
void	pa(struct s_stack_heads *heads);

/*
 * Pushes the top most element of stack A to the top of stack B.
 */
void	pb(struct s_stack_heads *heads);

/*
 * Rotates all elements in the stack A. The first element will become the last
 * one.
 */
void	ra(struct s_stack_heads *heads);

/*
 * Rotates all elements in the stack B. The first element will become the last
 * one.
 */
void	rb(struct s_stack_heads *heads);

/*
 * Rotates all elements in each stack, respectively. The last element will
 * become the last one.
 */
void	rr(struct s_stack_heads *heads);

/*
 * Rotates all elements in the stack A. The first element will become the last
 * one.
 */
void	rra(struct s_stack_heads *heads);

/*
 * Rotates all elements in the stack B. The first element will become the last
 * one.
 */
void	rrb(struct s_stack_heads *heads);

/*
 * Rotates all elements in each stack, respectively. The first element will
 * become the last one.
 */
void	rrr(struct s_stack_heads *heads);

#endif
