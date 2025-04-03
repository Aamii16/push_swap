/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:08 by meowy             #+#    #+#             */
/*   Updated: 2025/04/03 20:22:07 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_to_stack(t_stack **stack, char *str)
{
    char    **splited;
    int     i;
    void    *data;

    i = 0;
    if (!str)
        return ;
    splited = ft_split(str, ' ');
    while (splited[i])
    {
        data = (void *)((long)(ft_atoi(splited[i])));
        push(stack, new_node(data));
        i++;
    }
    free(splited);
}

int main(int ac, char **av)
{
    int     i;
    // int     j;
    t_stack *stack_a;

    stack_a = NULL;
    i = 1;
    // j = 0;
    if (ac == 1)
        return (0);
    while (i <= ac)
    {
        // if (!check_argument(av[i]))
        //     return (put_error("Error ch7aja\n"), -1);
        push_to_stack(&stack_a, av[i]);
        i++;
    }
    t_stack *tmp;
    tmp = stack_a;   
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