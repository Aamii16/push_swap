/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:08 by meowy             #+#    #+#             */
/*   Updated: 2025/04/09 05:11:56 by amzahir          ###   ########.fr       */
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
int	get_max(t_stack **to)
{
	t_stack	*curr;
	int		index;
	int		max;
	int		i;

	if (!to || !*to)
		return (-1);
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
		(*index)++;
		prev = curr;
		curr = curr->next;	
	}
	if (!found)
		*index = get_max(to);
	if ((*index) > (stack_size(to) / 2))
		return (stack_size(to) - (*index));
	else
		return ((*index));
}

int	find_node_index(t_stack **from, t_stack **to, int *indexT)
{
	t_stack	*tmp;
	int		min_cost;
	int		i;
	int		indexF;

	i = 0;
	min_cost = stack_size(from) + stack_size(to);
	tmp = *from;
	while (tmp)
	{
		if (min_cost > i + find_target_cost(to, tmp->data, indexT))
		{
			min_cost = i + find_target_cost(to, tmp->data, indexT) + 1;
			indexF = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (indexF);
}

void	moves(t_stack **from, t_stack **to)
{
	int		indexF;
	int		indexT;


	indexT = 0;
	indexF = find_node_index(from , to, &indexT);
	if (indexF > (stack_size(from) / 2) && indexT > (stack_size(to) / 2))
		rrr(from, to, indexF, indexT);
	else if (indexF !=1 && indexT != 0 &&
		indexF < (stack_size(from) / 2) && indexT < (stack_size(to) / 2))
		rr(from, to, indexF, indexT);
	else if (indexF != 0 && indexF < (stack_size(from) / 2))
		ra(from, indexF);
	else if ((indexF > (stack_size(from)) / 2))
		rra(from, indexF);
	else if (indexT != 0 && indexT < (stack_size(to) / 2))
		rb(from, indexT);
	else if ((indexT > (stack_size(to)) / 2))
		rrb(from, indexT);
	push(from, to);
	write(1, "pb\n", 3);
}

int main(int ac, char **av)
{
	int		i;
	// int	 j;
	t_stack *stack_a;

	stack_a = NULL;
	i = 0;
	// j = 0;
	if (ac == 0)
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
	//push(&stack_a, &stack_b);
	//moves(&stack_a, &stack_b);
	tmp = stack_b;
	if (tmp)
	{
		printf("stack_b\n");
		while (tmp)
		{
			printf("%d\n", (tmp->data));
			tmp = tmp->next;
		}	
	}
	tmp = stack_a;
	if (tmp)
	{
		printf("stack_a\n");
		while (tmp)
		{
			printf("%d\n", (tmp->data));
			tmp = tmp->next;
		}	
	}

	return (0);
}
