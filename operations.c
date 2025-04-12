#include "push_swap.h"

void	do_rr(t_stack **from, t_stack **to, int *indexF, int *indexT)
{
	if (!(*indexT) || !(*indexF))
		return ;
	while ((*indexF) && ((*indexT)))
	{
		(*indexF)--;
		(*indexT)--;
		rotate(from);
		rotate(to);
		write(1, "rr\n", 3);
	}
	while(*indexF > 0)
	{
		rotate(from);
		write(1, "ra\n", 3);
		(*indexF)--;
	}
	while(*indexT > 0)
	{
		rotate(to);
		write(1, "rb\n", 3);
		(*indexT)--;
	}
}

void	do_rrr(t_stack **from, t_stack **to, int *indexF, int *indexT)
{
	if (!(*indexT) || !(*indexF))
		return ;
	*indexF = stack_size(from) - *indexF;
	*indexT = stack_size(to) - *indexT	;
	while (*indexF && (*indexT))
	{
		(*indexF)--;
		(*indexT)--;
		reverse_rotate(from);
		reverse_rotate(to);
		write(1, "rrr\n", 4);
	}
	while(*indexF > 0)
	{
		reverse_rotate(from);
		write(1, "rra\n", 4);
		(*indexF)--;
	}
	while(*indexT > 0)
	{
		reverse_rotate(to);
		write(1, "rrb\n", 4);
		(*indexT)--;
	}
}
