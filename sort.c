/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:33:10 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 00:49:47 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (index);
		index++;
		prev = curr;
		curr = curr->next;
	}
	return (get_max(b));
}

static int	find_node_index(t_stack **a, t_stack **b, int *index_b)
{
	t_stack	*tmp;
	int		min_cost;
	int		i;
	int		index_a;
	int		tmp_index;

	i = 0;
	index_a = 0;
	min_cost = stack_size(a) + stack_size(b);
	tmp = *a;
	while (tmp)
	{
		tmp_index = index_of_b_target(b, tmp->data);
		if (min_cost > cost(a, i) + cost(b, tmp_index) + 1)
		{
			min_cost = cost(a, i) + cost(b, tmp_index) + 1;
			index_a = i;
			*index_b = tmp_index;
		}
		i++;
		tmp = tmp->next;
	}
	return (index_a);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int		index_a;
	int		index_b;
	int		size_a;
	int		size_b;

	index_b = 0;
	size_a = stack_size(a);
	size_b = stack_size(b);
	index_a = find_node_index(a, b, &index_b);
	if ((index_a > (size_a / 2)) && (index_b > (size_b / 2)))
		do_rrr(a, b, &index_a, &index_b);
	else if ((index_a <= (size_a / 2)) && ((index_b <= (size_b / 2))))
		do_rr(a, b, &index_a, &index_b);
	if (index_a <= (size_a / 2))
		do_ra(a, &index_a);
	else if (index_a > (size_a / 2))
		do_rra(a, &index_a);
	if (index_b <= (size_b / 2))
		do_rb(b, &index_b);
	else if (index_b > (size_b / 2))
		do_rrb(b, &index_b);
	push(a, b);
	write(1, "pb\n", 3);
}

int	index_of_a_target(t_stack **a, int val)
{
	t_stack	*tmp;
	long	min_diff;
	int		index;
	int		found;
	int		i;

	tmp = *a;
	i = 0;
	index = 0;
	found = tmp->data;
	min_diff = __LONG_MAX__ - 1;
	while (tmp)
	{
		if (min_diff > ft_abs(val - tmp->data) && tmp->data > val)
		{
			min_diff = ft_abs(val - tmp->data);
			index = i;
			found = tmp->data;
		}
		tmp = tmp->next;
		i++;
	}
	if (found < val)
		return (get_min(a));
	return (index);
}

void	push_to_a(t_stack **b, t_stack **a)
{
	int		index_a;
	int		size_a;

	size_a = stack_size(a);
	index_a = index_of_a_target(a, (*b)->data);
	if (index_a < (size_a / 2))
		do_ra(a, &index_a);
	else
		do_rra(a, &index_a);
	pa(b, a);
}
