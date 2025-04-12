/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:14:18 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/12 03:30:02 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != '\0')
		return(0);
	return (1);
}
//fix this nigga
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
				free_stack(stack);
				put_error("Error DUPS\n");
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp2->next;
	}
	return (1);
}