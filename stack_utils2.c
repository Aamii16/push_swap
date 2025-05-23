/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:32:45 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 00:46:27 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack		*tmp_from;

	if (!from || !*from || !to)
		return ;
	tmp_from = *from;
	if (!*to)
	{
		*to = tmp_from;
		*from = (*from)->next;
		(*to)->next = NULL;
		return ;
	}
	(*from) = (*from)->next;
	tmp_from->next = *to;
	*to = tmp_from;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	head = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	(*stack) = (*stack)->next;
	head->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*tmp;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	tmp = *stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap(t_stack *prev, t_stack *curr)
{
	int	tmp;

	tmp = prev->data;
	prev->data = curr->data;
	curr->data = tmp;
}

t_stack	*last_node(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
