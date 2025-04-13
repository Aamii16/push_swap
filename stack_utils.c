/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:32:56 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 00:43:34 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

void	add_node(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = node;
			break ;
		}
		tmp = tmp->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*pre;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		pre = curr;
		curr = curr->next;
		free(pre);
	}
	*stack = NULL;
}

int	stack_size(t_stack	**stack)
{
	t_stack	*tmp;
	int		size;

	if (!stack || !*stack)
		return (0);
	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	init_stack(t_stack **stack, char *str)
{
	char	**splited;
	int		i;
	int		data;

	i = -1;
	if (!str || !stack)
		return (0);
	splited = ft_split(str, ' ');
	while (splited && splited[++i])
	{
		if (!is_number(splited[i]) || ft_atol(splited[i]) > INT_MAX
			|| ft_atol(splited[i]) < INT_MIN)
			return (free_pt(splited, i), 0);
	}
	i = -1;
	while (splited && splited[++i])
	{
		data = (int)ft_atol(splited[i]);
		add_node(stack, new_node(data));
	}
	check_duplicates(stack);
	free_pt(splited, i);
	return (1);
}
