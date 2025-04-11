
#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

void	add_node(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;	
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = node;
			break ;
		}
		tmp = tmp->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack *pre;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		pre = curr;
		curr = curr->next;
		free (pre);	
	}
	*stack = NULL;
}

int	stack_size(t_stack	**stack)
{
	t_stack	*tmp;
	int		size;

	if (!stack || !*stack)
		return (0);
	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);	
}

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

void	init_stack(t_stack **stack, char *str)
{
	char	**splited;
	int		i;
	int		data;

	i = -1;
	if (!str || !stack)
		return ;
	splited = ft_split(str, ' ');
	while (splited[++i])
	{
		if (!is_number(splited[i]))
		{
			free_pt(splited, i);
			put_error("Error\n");
			exit(1);
		}
	}
	i = 0;
	while (splited[i])
	{
		data = ft_atoi(splited[i]);
		add_node(stack, new_node(data));
		i++;
	}
	free_pt(splited, i);
}
