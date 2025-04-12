
#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		//printf("%d->", tmp->data);
		tmp = tmp->next;	
	}
	//printf("\n");
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
	//if (tmp)
		//printf("node at index %d is %d\n", index, tmp->data);
	//else
		//printf("index out of range\n");
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int	min;

	stack_b = NULL;
	if (stack_size(stack_a) > 3)
		pb(stack_a, &stack_b);
	if (stack_size(stack_a) > 4)
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

int main(int ac, char **av)
{
	int		i;
	int		sizeA;
	t_stack *stack_a;
	
	stack_a = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	while (i <= ac)
	{
		init_stack(&stack_a, av[i]);
		i++;
	}
	//check_duplicates(stack_a); FIX THIS NIGGA
	sizeA = stack_size(&stack_a);
	if (sizeA == 3)
		sort_three(&stack_a);
	else if (sizeA > 3)
		sort(&stack_a);
	//print_stack(&stack_b);
	//print_stack(stack_a);
	return (0);
}
