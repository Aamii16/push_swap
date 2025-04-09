/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:08 by meowy             #+#    #+#             */
/*   Updated: 2025/04/09 02:09:15 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_target_cost(t_stack **to, int val, int *index)
{
	t_stack	*curr;
	t_stack	*prev;
	int		found;

	found = 0;
	curr = *to;
	prev = last_node(*to);
	*index = 0;
	while (curr)
	{
		if (curr->data <= val && prev->data >= val)
		{
			found = 1;	
			break ;
		}
		prev = curr;
		curr = curr->next;
		(*index)++;
	}
	if ((*index) > stack_size(to) / 2)
		return (stack_size(to) - *index + 1);
	else
		return (*index + 1);
	
}

t_stack	*find_node(t_stack **from, t_stack **to, int *indexF, int *indexT)
{
	t_stack	*tmp;
	t_stack	*best;
	int		min_cost;
	int		i;

	i = 0;
	min_cost = stack_size(from) + stack_size(to);
	tmp = *from;
	while (tmp)
	{
		if (min_cost > i + find_target_cost(to, tmp->data, indexT))
		{
			min_cost = i + find_target_cost(to, tmp->data, indexT);
			*indexF = i;
			best = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (best);
}
{
	t_stack	*curr;
	int		index;
	int		max;

	if (!to || !*to)
		return (0);
	curr = *to;
	max = curr->data;
	index = 0;
	while (curr)
	{
		if (curr->data > max)
		{
			max = curr->data;
			index++;
		}
		curr = curr->next;	
	}
	return (index);
}

void	moves(t_stack **from, t_stack **to)
{
	t_stack	*tmpFrom;
	t_stack	*tmpTo;
	t_stack	*best;
	int		indexF;
	int		indexT;

	best = find_node(from , to, &indexF, &indexT);
	if (indexF > stack_size(from) / 2 && indexT > stack_size(to) / 2)
		do_rrr(from, to, indexF, indexT);
	else if (indexF < stack_size(from) / 2 && indexT < stack_size(to) / 2)
		do_rr(from, to, indexF, indexT);
	else if (indexF < stack_size(from))
		do_ra(from, indexF);
	else if ((indexF > stack_size(from)))
		do_rra(from, indexF);
	else if (indexT < stack_size(from))
		do_rb(from, indexF);
	else
		do_rrb(from, indexF);
	push(from, to);
	write(1, "pb\n", 3);
}

int main(int ac, char **av)
{
	int		i;
	// int	 j;
	t_stack *stack_a;

	stack_a = NULL;
	i = 1;
	// j = 0;
	if (ac == 1)
		return (0);
	while (i <= ac)
	{
		//if (!check_argument(av[i]))
			//return (put_error("Error ch7aja\n"), -1); // fix this nigga
		init_stack(&stack_a, av[i]);
		i++;
	}
	t_stack *stack_b;
	stack_b = NULL;
	t_stack *tmp;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	moves(&stack_a, &stack_b);
	tmp = stack_b;
	if (tmp)
	{
		while (tmp)
		{
			printf("%d\n", (tmp->data));
			tmp = tmp->next;
		}	
	}
	return (0);
}
