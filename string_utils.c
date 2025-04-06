/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:19 by meowy             #+#    #+#             */
/*   Updated: 2025/04/05 16:29:37 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	while (src[src_size])
			src_size++;
	i = 0;
	if (!size)
		return (src_size);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	return (src_size);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - 48);
	return (num * sign);
}
