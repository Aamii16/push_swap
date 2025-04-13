/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:33:36 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 00:33:37 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack **from, int *indexF)
{
	if (!(*indexF))
		return ;
	while (*indexF > 0)
	{
		rotate(from);
		write(1, "ra\n", 3);
		(*indexF)--;
	}
}

void	do_rb(t_stack **to, int *indexT)
{
	if (!(*indexT))
		return ;
	while (*indexT > 0)
	{
		rotate(to);
		write(1, "rb\n", 3);
		(*indexT)--;
	}
}

void	do_rra(t_stack **from, int *indexF)
{
	if (!(*indexF))
		return ;
	*indexF = stack_size(from) - *indexF;
	while (*indexF > 0)
	{
		reverse_rotate(from);
		write(1, "rra\n", 4);
		(*indexF)--;
	}
}

void	do_rrb(t_stack **to, int *indexT)
{
	if (!(*indexT))
		return ;
	*indexT = stack_size(to) - *indexT;
	while (*indexT > 0)
	{
		reverse_rotate(to);
		write(1, "rrb\n", 4);
		(*indexT)--;
	}
}
