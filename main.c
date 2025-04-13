/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:34:25 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 02:25:35 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		min;

	stack_b = NULL;
	if (stack_size(stack_a) > 3)
		pb(stack_a, &stack_b);
	if (stack_size(stack_a) > 3)
		pb(stack_a, &stack_b);
	while (stack_size(stack_a) > 3)
		push_to_b(stack_a, &stack_b);
	if (stack_size(stack_a) == 3)
		sort_three(stack_a);
	while (stack_size(&stack_b))
	{
		push_to_a(&stack_b, stack_a);
	}
	min = get_min(stack_a);
	if (min)
	{
		if (min <= stack_size(stack_a) / 2)
			do_ra(stack_a, &min);
		else
			do_rra(stack_a, &min);
	}
}

void	check_size(t_stack **stack_a)
{
	int		size;

	size = stack_size(stack_a);
	if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
		{
			swap(*stack_a, (*stack_a)->next);
			write(1, "sa\n", 3);
		}
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3)
		sort(stack_a);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		if (!init_stack(&stack_a, av[i]))
		{
			put_error("Error\n");
			free_stack(&stack_a);
			return (1);
		}
		i++;
	}
	if (!sorted(&stack_a))
		check_size(&stack_a);
	free_stack(&stack_a);
	return (0);
}
