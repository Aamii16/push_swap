#include "push_swap.h"

static int	index_of_b_target(t_stack **b, int val)
{
	t_stack	*curr;
	t_stack	*prev;
	int		index;

	curr = *b;
	prev = last_node(*b);
	index = 0;
	while (curr)
	{
		if (curr->data < val && prev->data > val)
			return(index);
		index++;
		prev = curr;
		curr = curr->next;	
	}
	return (get_max(b));
}

static int	find_node_index(t_stack **a, t_stack **b, int *indexB)
{
	t_stack	*tmp;
	int		min_cost;
	int		i;
	int		indexA;
	int		tmp_index;

	i = 0;
	indexA = 0;
	min_cost = stack_size(a) + stack_size(b);
	tmp = *a;
	while (tmp)
	{
		tmp_index = index_of_b_target(b, tmp->data);
		if (min_cost > cost(a, i) + cost(b, tmp_index) + 1)
		{
			min_cost = cost(a, i) + cost(b, tmp_index) + 1;
			indexA = i;
			*indexB = tmp_index;
		}
		i++;
		tmp = tmp->next;
	}
	return (indexA);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int		indexA;
	int		indexB;
	int		sizeA;
	int		sizeB;

	indexB = 0;
	sizeA = stack_size(a);
	sizeB = stack_size(b);
	indexA = find_node_index(a , b, &indexB);
	printf("selected: %d from A to %d in B\n", indexA, indexB);
	if ((indexA > (sizeA / 2)) && (indexB > (sizeB / 2)))
		do_rrr(a, b, &indexA, &indexB);
	else if ((indexA <= (sizeA / 2)) && ((indexB <= (sizeB / 2))))
		do_rr(a, b, &indexA, &indexB);
	if (indexA <= (sizeA / 2))
		do_ra(a, &indexA);
	else if (indexA > (sizeA / 2))
		do_rra(a, &indexA);
	if (indexB <= (sizeB / 2))
		do_rb(b, &indexB);
	else if (indexB > (sizeB / 2))
		do_rrb(b, &indexB);
	
	push(a, b);
	write(1, "pb\n", 3);
}

int		index_of_a_target(t_stack **to, int val)
{
	t_stack	*tmp;
	long	min_diff;
	int		index;
	int		max;
	int		i;

	tmp = *to;
	max  = get_max(to);
	i = 0;
	index = 0;
	min_diff = __LONG_MAX__ - max;
	while (tmp)
	{
		if (min_diff > ft_abs(val - tmp->data))
		{
			min_diff = ft_abs(val - tmp->data);
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	push_to_a(t_stack **b, t_stack **a)
{
	int		indexA;
	int		sizeT;

	sizeT = stack_size(a);
	indexA = index_of_a_target(a, (*b)->data);
	if (indexA < (sizeT / 2))
		do_ra(a, &indexA);
	else
		do_rra(a, &indexA);
	pa(b, a);
}