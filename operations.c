/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:33:47 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 00:57:56 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr(t_stack **a, t_stack **b, int *index_a, int *index_b)
{
	if (!(*index_b) || !(*index_a))
		return ;
	while ((*index_a) && ((*index_b)))
	{
		(*index_a)--;
		(*index_b)--;
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	while (*index_a > 0)
	{
		rotate(a);
		write(1, "ra\n", 3);
		(*index_a)--;
	}
	while (*index_b > 0)
	{
		rotate(b);
		write(1, "rb\n", 3);
		(*index_b)--;
	}
}

void	do_rrr(t_stack **a, t_stack **b, int *index_a, int *index_b)
{
	if (!(*index_b) || !(*index_a))
		return ;
	*index_a = stack_size(a) - *index_a;
	*index_b = stack_size(b) - *index_b;
	while (*index_a && (*index_b))
	{
		(*index_a)--;
		(*index_b)--;
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
	while (*index_a > 0)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		(*index_a)--;
	}
	while (*index_b > 0)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
		(*index_b)--;
	}
}
