/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:08 by meowy             #+#    #+#             */
/*   Updated: 2025/04/06 01:42:42 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack(t_stack **stack, char *str)
{
	char	**splited;
	int		i;
	int		data;

	i = 0;
	if (!str || !stack)
		return ;
	splited = ft_split(str, ' ');
	while (splited[i])
	{
		data = ft_atoi(splited[i]);
		add_node(stack, new_node(data));
		i++;
	}
	free_pt(splited, i);
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

int	cost(t_stack **stack, int val)
{
	int		cost;	
	
	return (cost);
}

void	shi7aja(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*curr_b;
	t_stack	*prev_b;
	int		min_cost;
	int		index;
	
	
	if (!stack_a || !*stack_a)
		return ;
	index = 0;
	min_cost = stack_size(stack_a) + stack_size(stack_b);
	tmp_a = *stack_a;
	prev_b = last_node(stack_b);
	while(tmp_a)
	{
		curr_b = *stack_b;
		while (curr_b)
		{
			if (tmp_a->data <= prev_b->data && tmp_a->data >= curr_b->data)
			{
				if (min_cost > cost(stack_a, stack_b, ))
				{
					min_cost
				}
			}
			prev_b = curr_b;
			curr_b = curr_b->next;
		}
		index++;
		tmp_a = tmp_a->next;
	}
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
