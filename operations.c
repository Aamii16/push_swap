#include "push_swap.h"

void	do_rr(t_stack **from, t_stack **to, int *indexF, int *indexT)
{
	if (!(*indexT) || !(*indexF))
		return ;
	printf("before indexF: %d indexT %d\n", *indexF, *indexT);
	while ((*indexF)-- && ((*indexT))--)
	{
		rotate(from);
		rotate(to);
		write(1, "rr\n", 3);
	}
	printf(" AFTER indexF: %d indexT %d\n", *indexF, *indexT);
	while(*indexF > 0 && (*indexF)--)
	{
		rotate(from);
		write(1, "ra\n", 3);
	}
	while(*indexT > 0 && (*indexT)--)
	{
		printf("indexT: %d\n", *indexT);
		rotate(to);
		write(1, "rb\n", 3);
		
	}
}

void	do_rrr(t_stack **from, t_stack **to, int *indexF, int *indexT)
{
	if (!(*indexT) || !(*indexF))
		return ;
	*indexF = stack_size(from) - *indexF;
	*indexT = stack_size(to) - *indexT;
	while ((*indexF)-- && ((*indexT))--)
	{
		reverse_rotate(from);
		reverse_rotate(to);
		write(1, "rrr\n", 4);
	}
	while(*indexF > 0 && (*indexF)--)
	{
		write(1, "rra\n", 4);
		reverse_rotate(from);
	}
	while(*indexT > 0 &&((*indexT))--)
	{
		reverse_rotate(to);
		write(1, "rrb\n", 4);
	}
}

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
	while (((*indexT))--)
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
	while ((*indexF)--)
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
	while (((*indexT))--)
	{
		reverse_rotate(to);
		write(1, "rrb\n", 4);
	}
}
void	do_pb(t_stack **from, t_stack **to)
{
	push(from, to);
	write(1, "pb\n", 3);
}