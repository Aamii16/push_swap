#include "push_swap.h"

void	rr(t_stack **from, t_stack **to, int indexF, int indexT)
{
	while (indexF-- && (indexT)--)
	{
		rotate(from);
		rotate(to);
		write(1, "rr\n", 3);
	}
	while(indexF--)
	{
		rotate(from);
		write(1, "ra\n", 3);
	}
	while(indexT--)
	{
		rotate(to);
		write(1, "rb\n", 3);
	}
}

void	rrr(t_stack **from, t_stack **to, int indexF, int indexT)
{
	indexF = stack_size(from) - indexF;
	indexT = stack_size(to) - indexT;
	while (indexF-- && (indexT)--)
	{
		reverse_rotate(from);
		reverse_rotate(to);
		write(1, "rrr\n", 4);
	}
	while(indexF--)
	{
		reverse_rotate(from);
		write(1, "rra\n", 4);
	}
	while((indexT)--)
	{
		reverse_rotate(to);
		write(1, "rrb\n", 4);
	}
}

void	ra(t_stack **from, int indexF)
{
	while (indexF--)
	{
		rotate(from);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **to, int indexT)
{
	while ((indexT)--)
	{
		rotate(to);
		write(1, "rb\n", 3);
	}
}

void	rra(t_stack **from, int indexF)
{
	indexF = stack_size(from) - indexF;
	while (indexF--)
	{
		reverse_rotate(from);
		write(1, "rra\n", 3);
	}
}

void	rrb(t_stack **to, int indexT)
{
	indexT = stack_size(to) - indexT;
	while ((indexT)--)
	{
		rotate(to);
		write(1, "rrb\n", 3);
	}
}