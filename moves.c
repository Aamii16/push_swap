#include "push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}