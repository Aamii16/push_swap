/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:14:18 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/05 22:23:01 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_argument(char *str)//fix this nigga
{
	if (!str)
		return (0);
	while (*str)
	{
		if ((*str == '+' || *str == '-') &&
			(*(str + 1) <'0' || *(str + 1) > '9'))
			return (0);
		if (*str == '+' || *str == '-' || *str == ' ')
			str++;
		else if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int	check_duplicates(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stack)
		return (0);
	tmp1 = *stack;
	while (tmp1)
	{
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
			{
				//free_stack(stack);
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp2->next;
	}
	return (1);
}