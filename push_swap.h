/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:03 by meowy             #+#    #+#             */
/*   Updated: 2025/04/10 07:49:56 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
    int				data;
    struct s_stack	*next;
}       t_stack;
//string utils

int ft_atoi(char *str);
void	put_error(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	free_pt(char **split, int e);
char    **ft_split(char const *s, char c);

//stack utils
t_stack *new_node(int data);
void	add_node(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
int		stack_size(t_stack **stack);
void	init_stack(t_stack **stack, char *str);

void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	swap(t_stack *node1, t_stack *node2);
//operations
void	do_rr(t_stack **from, t_stack **to, int *indexF, int *indexT);
void	do_rrr(t_stack **from, t_stack **to, int *indexF, int *indexT);
void	do_ra(t_stack **from, int *indexF);
void	do_rb(t_stack **to, int *indexT);
void	do_rra(t_stack **from, int *indexF);
void	do_rrb(t_stack **to, int *indexT);
void	do_pb(t_stack **from, t_stack **to);

//moves
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);


//parsing utils
int	check_duplicates(t_stack **stack);
int check_argument(char *str);


#endif