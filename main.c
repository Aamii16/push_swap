/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:08 by meowy             #+#    #+#             */
/*   Updated: 2025/04/06 21:31:13 by amzahir          ###   ########.fr       */
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

int	count_cost(t_stack **stack, int val)
{
	int		cost;	
	int		i;
	t_stack	*tmp;
	
	tmp = *stack;
	cost = 0;
	while (tmp)
	{
		if (tmp->data == val)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i < stack_size(stack) / 2)
		cost = i;
	else
		cost = stack_size(stack) - i;
	return (cost + 1);
}

int	cost_b(t_stack **stack_b, int val)
{
	t_stack	*curr_b;
	t_stack	*prev_b;
	int		min_cost;

	prev_b = last_node(stack_b);
	curr_b = *stack_b;
	min_cost = stack_size(stack_a) + stack_size(stack_b);
	while (curr_b)
	{
		if (val <= prev_b->data && val >= curr_b->data)
		{
			if (min_cost > cost(stack_a, val) + cost(stack_b, curr_b->data))
			{
				min_cost = cost(stack_a, val) + cost(stack_b, curr_b->data);
				index = i;			
			}
		}
		prev_b = curr_b;
		curr_b = curr_b->next;
		i++;
		tmp_a = tmp_a->next;
	}
}

int	find_node_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	int		index;
	int		i;
	
	if (!stack_a || !*stack_a)
		return ;
	index = 0;
	tmp_a = *stack_a;
	while(tmp_a)
	{
	}
	return (index);
}
void	moves(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	i = find_node(stack_a, stack_b);
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while 
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
		push_to_stack(&stack_a, av[i]);
		i++;
	}
	t_stack *stack_b;
	stack_b = NULL;
	push_to_stack(&stack_b, "6 7 8 9 10");
	t_stack *tmp;
	
	push(&stack_a, &stack_b);
	tmp = stack_b;
	if (tmp)
	{
		while (tmp)
		{
			printf("%d\n", (int)(long)(tmp->data));
			tmp = tmp->next;
		}	
	}
	return (0);
}
