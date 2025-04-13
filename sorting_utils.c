/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:33:03 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 01:03:29 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_stack **stack, int index)
{
	int	size;

	size = stack_size(stack);
	if (index > (size / 2))
		return (size - index);
	else
		return (index);
}

int	get_max(t_stack **to)
{
	t_stack	*curr;
	int		index;
	int		max;
	int		i;

	curr = *to;
	max = curr->data;
	i = 0;
	index = 0;
	while (curr)
	{
		if (curr->data > max)
		{
			max = curr->data;
			index = i;
		}
		i++;
		curr = curr->next;
	}
	return (index);
}

int	get_min(t_stack **to)
{
	t_stack	*curr;
	int		index;
	int		min;
	int		i;

	if (!to || !*to)
		return (-1);
	curr = *to;
	min = curr->data;
	i = 0;
	index = 0;
	while (curr)
	{
		if (curr->data < min)
		{
			min = curr->data;
			index = i;
		}
		i++;
		curr = curr->next;
	}
	return (index);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && first > third && second > third)
	{
		ra(a);
		sa(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first > third)
		rra(a);
	else if (first > second && first < third)
		sa(a);
	else if (first < second && first < third && second > third)
	{
		rra(a);
		sa(a);
	}
}
