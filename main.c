
#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;	
	}
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


void sort_three(t_stack **stack)
{
    int first = (*stack)->data;
    int second = (*stack)->next->data;
    int third = (*stack)->next->next->data;

    if (first > second && second > third)
    {
        swap(*stack, (*stack)->next);
		write(1, "sa\n", 3);
        rra(stack);
    }
    if (first > second && first < third)
	{
		swap(*stack, (*stack)->next);
		write(1, "sa\n", 3);
	}
    if (first > second && second < third && first > third)
        ra(stack);
    if (first < second && second > third && first < third)
    {
		swap(*stack, (*stack)->next);
		write(1, "sa\n", 3);
        ra(stack);
    }
    if (first < second && second > third && first > third)
        rra(stack);
}
void print_node_at_index(t_stack **stack, int index)
{
	t_stack	*tmp;
	int		i;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (i == index)
			break ;
		i++;
		tmp = tmp->next;	
	}
	if (tmp)
		printf("node at index %d is %d\n", index, tmp->data);
	else
		printf("index out of range\n");
}

int	get_max(t_stack **to)
{
	t_stack	*curr;
	int		index;
	int		max;
	int		i;

	if (!to || !*to)
		return (-1);
	curr = *to;
	max = curr->data;
	i = 0;
	index = 0;
	while (curr)
	{
		if (curr->data > max)
		{
			max = curr->data;
			index = i;
			printf("max node at index %d is %d\n", index, max);
		}
		i++;
		curr = curr->next;	
	}
	return (index);
}

int	find_target_index(t_stack **to, int val)
{
	t_stack	*curr;
	t_stack	*prev;
	int		found;
	int		index;

	found = 0;
	curr = *to;
	prev = last_node(*to);
	index = 0;
	while (curr)
	{
		if (curr->data <= val && prev->data >= val)
		{
			found = 1;
			break ;
		}
		index++;
		prev = curr;
		curr = curr->next;	
	}
	if (!found)
		index = get_max(to);
	return (index);
}

int	cost(t_stack **stack, int index)
{
	int	size;

	size = stack_size(stack);
	if (index > (size / 2))
		return (size - index);
	else
		return (index);
}

int	find_node_index(t_stack **from, t_stack **to, int *indexT)
{
	t_stack	*tmp;
	int		min_cost;
	int		i;
	int		indexF;
	int		tmp_index;

	i = 0;
	indexF = 0;
	min_cost = stack_size(from) + stack_size(to);
	tmp = *from;
	while (tmp)
	{
		tmp_index = find_target_index(to, tmp->data);
		//indexT value is changed in each call of find_target_cost so the best target index is lost 
		if (min_cost > cost(from, i) + cost(to, tmp_index) + 1)
		{
			min_cost = cost(from, i) + cost(to, tmp_index) + 1;
			indexF = i;
			*indexT = tmp_index;
		}
		i++;
		tmp = tmp->next;
	}
	return (indexF);
}

void	moves(t_stack **from, t_stack **to)
{
	int		indexF;
	int		indexT;
	int		sizeF;
	int		sizeT;

	indexT = 0;
	sizeF = stack_size(from);
	sizeT = stack_size(to);
	indexF = find_node_index(from , to, &indexT);
	printf("from ");print_node_at_index(from, indexF);
	printf("to ");print_node_at_index(to, indexT);
	if (indexF && indexT && indexF > (sizeF / 2)
		&& indexT > (sizeT / 2))
		do_rrr(from, to, &indexF, &indexT);
	else if (indexF && indexT && indexF <= (sizeF / 2)
		&& indexT <= (sizeT / 2))
		do_rr(from, to, &indexF, &indexT);
	if (indexF && indexF <= (sizeF / 2))
		do_ra(from, &indexF);
	else if (indexF && indexF > (sizeF / 2))
		do_rra(from, &indexF);
	if (indexT <= (sizeT / 2))
		do_rb(to, &indexT);
	else if (indexT && indexT > (sizeT / 2))
		do_rrb(to, &indexT);
	
	push(from, to);
	write(1, "pb\n", 3);
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
		init_stack(&stack_a, av[i]);
		i++;
	}
	t_stack *stack_b;
	stack_b = NULL;
	if (!stack_b)
	{
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
	}
	while (stack_size(&stack_a) > 3)
		moves(&stack_a, &stack_b);
	//printf("stack a size %d\n", stack_size(&stack_a));
	if (stack_size(&stack_a) == 3)
	{
		sort_three(&stack_a);
	}
	//printf("stackb\n");
	//print_stack(&stack_b);
	//printf("stacka\n");
	//print_stack(&stack_a);
	return (0);
}
