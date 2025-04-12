#include "push_swap.h"

void	do_ra(t_stack **from, int *indexF)
{
	if (!(*indexF))
		return ;
	while (*indexF > 0 &&(*indexF)--)
	{
		rotate(from);
		write(1, "ra\n", 3);
	}
}

void	do_rb(t_stack **to, int *indexT)
{
	if (!(*indexT))
		return ;
	while (*indexT > 0 && ((*indexT))--)
	{
		rotate(to);
		write(1, "rb\n", 3);
	}
}

void	do_rra(t_stack **from, int *indexF)
{
	if (!(*indexF))
		return ;
	*indexF = stack_size(from) - *indexF;
	while (*indexF > 0 && (*indexF)--)
	{
		reverse_rotate(from);
		write(1, "rra\n", 4);
	}
}

void	do_rrb(t_stack **to, int *indexT)
{
	if (!(*indexT))
		return ;
	*indexT = stack_size(to) - *indexT;
	while (*indexT > 0 && ((*indexT))--)
	{
		reverse_rotate(to);
		write(1, "rrb\n", 4);
	}
}
