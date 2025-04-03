/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meowy <meowy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:03 by meowy             #+#    #+#             */
/*   Updated: 2025/04/02 19:13:56 by meowy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
    void            *data;
    struct s_stack   *next;
}       t_stack;

int check_argument(char *str);
int ft_atoi(char *str);
void	put_error(char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	free_pt(char **split, int e);
int	check_duplicates(char **split);
void    put_error(char *str);
char    **ft_split(char const *s, char c);

t_stack *new_node(void	*data);

void	push(t_stack **stack, t_stack *node);

#endif