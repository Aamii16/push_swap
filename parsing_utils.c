/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:14:18 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/03 20:21:41 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_arguments(char *str)
{
    if (*str)
        return (0);
    while (*str)
    {
        if (*str == '+' || *str == '-' || *str == ' ')
            str++;
        else if (*str >= '0' && *str <= '9')
            str++;
        else
            return (0);
    }   
    return (1);
}